using CalculatorCLI;
using CalculatorWPF.Models;
using CalculatorWPF.Resources;
using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace CalculatorWPF.Services;

public partial class CalculatorService : ObservableObject, ICalculatorService
{
    private readonly ICalculator _calculator = App.Ioc.GetRequiredService<ICalculator>();

    private ExpressionException? _shownException;

    [ObservableProperty]
    private string _summary = string.Empty;

    [ObservableProperty]
    private string _expression = string.Empty;

    public ObservableCollection<CalculationEntry> CalculationEntries { get; } = [];

    public ObservableCollection<CalculationEntry> MemoryEntries { get; } = [];

    public CalculatorService()
    {
        LocalizedResources.Instance.PropertyChanged += LocalizedResources_PropertyChanged;
    }

    public bool PerformCalculation(out double value)
    {
        value = 0;
        _shownException = null;

        try
        {
            var acceptedExpression = Expression
                .Replace('×', '*')
                .Replace('÷', '/');

            value = _calculator.Calculate(acceptedExpression);
            Summary = Expression + " =";
            Expression = value.ToString();
            return true;
        }
        catch (ExpressionException ex)
        {
            _shownException = ex;
            UpdateSummary(ex);
            return false;
        }
    }

    public void AppendToExpression(string number)
    {
        Summary = "";

        if (string.IsNullOrEmpty(Expression))
        {
            Expression = number;
            return;
        }

        var lastChar = Expression[^1];
        
        if (char.IsNumber(lastChar))
        {
            Expression = number;
            return;
        }

        if (lastChar == ')')
        {
            Expression = $"{Expression}×{number}";
            return;
        }

        if (number.StartsWith('-'))
        {
            Expression += $"({number})";
            return;
        }

        Expression += number;
    }

    private void UpdateSummary(ExpressionException ex)
    {
        var charString = string.IsNullOrEmpty(Expression) ? "" : ex.Expression[ex.Position].ToString();
        var summaryTemplate = LocalizedResources.Instance["ExpressionExceptionSummary"];
        
        if (string.IsNullOrEmpty(summaryTemplate))
        {
            Summary = string.Empty;
            return;
        }

        Summary = string.Format(summaryTemplate, ex.Position, charString);
    }

    private void LocalizedResources_PropertyChanged(object? sender, PropertyChangedEventArgs e)
    {
        if (e.PropertyName != string.Empty)
        {
            return;
        }

        if (_shownException is null)
        {
            return;
        }

        UpdateSummary(_shownException);
    }

    public void Dispose()
    {
        _calculator.Dispose();
        LocalizedResources.Instance.PropertyChanged -= LocalizedResources_PropertyChanged;
        GC.SuppressFinalize(this);
    }
}
