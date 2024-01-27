using CalculatorCLI;
using CalculatorWPF.Models;
using CalculatorWPF.Resources;
using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace CalculatorWPF.Services;

public class CalculatorService : ObservableObject, ICalculatorService
{
    private readonly ICalculator _calculator = App.Ioc.GetRequiredService<ICalculator>();

    private ExpressionException? _shownException;

    private string _summary = string.Empty;
    public string Summary
    {
        get => _summary;
        set
        {
            SetProperty(ref _summary, value);
        }
    }

    private string _expression = string.Empty;
    public string Expression
    {
        get => _expression;
        set
        {
            SetProperty(ref _expression, value);
        }
    }

    public ObservableCollection<CalculationEntry> CalculationEntries { get; } = new();

    public ObservableCollection<MemoryEntry> MemoryEntries { get; } = new();

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
            value = _calculator.Calculate(Expression);
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
