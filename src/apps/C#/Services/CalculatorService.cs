using CalculatorCLI;
using CalculatorWPF.Models;
using CommunityToolkit.Mvvm.ComponentModel;
using System;
using System.Collections.ObjectModel;

namespace CalculatorWPF.Services;

public class CalculatorService : ObservableObject, ICalculatorService
{
    private readonly ICalculator _calculator = App.Ioc.GetRequiredService<ICalculator>();

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

    public bool PerformCalculation(out double value)
    {
        try
        {
            value = _calculator.Calculate(Expression);
            Summary = Expression + " =";
            Expression = value.ToString();
            return true;
        }
        catch (ExpressionException ex)
        {
            var charString = string.IsNullOrEmpty(Expression) ? "" : $"('{ex.Expression[ex.Position]}')";
            Summary = $"Error: {ex.Message} Position: {ex.Position}{charString}.";
            value = 0;
            return false;
        }
    }

    public void Dispose()
    {
        _calculator.Dispose();
        GC.SuppressFinalize(this);
    }
}
