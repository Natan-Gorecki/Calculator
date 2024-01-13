using CalculatorCLI;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MainWindowViewModel : ObservableObject, IDisposable
{
    private readonly Calculator _calculator = new Calculator();

    private string _summary = string.Empty;
    public string Summary
    {
        get => _summary;
        set
        {
            _summary = value;
            OnPropertyChanged(nameof(Summary));
        }
    }

    private string _expression = string.Empty;
    public string Expression
    {
        get => _expression;
        set
        {
            _expression = value;
            OnPropertyChanged(nameof(Expression));
        }
    }

    public ICommand Calculate { get; }
    public ICommand ClearEntry { get; }
    public ICommand ClearAll { get; }
    public ICommand ClearLast { get; }
    public ICommand AppendChar { get; }

    public MainWindowViewModel()
    {
        _calculator = new Calculator();
        Calculate = new RelayCommand(OnCalculate);
        ClearEntry = new RelayCommand(OnClearEntry);
        ClearAll = new RelayCommand(OnClearAll);
        ClearLast = new RelayCommand(OnClearLast);
        AppendChar = new RelayCommand<string>(OnAppendChar);
    }

    private void OnCalculate()
    {
        try
        {
            var result = _calculator.Calculate(Expression);
            Summary = Expression + " =";
            Expression = result.ToString();
        }
        catch (ExpressionException ex)
        {
            Summary = $"Error: {ex.Message} Position: {ex.Position}('{ex.Expression[ex.Position]}').";
        }
    }

    private void OnClearEntry()
    {
        Expression = "";
    }

    private void OnClearAll()
    {
        Summary = "";
        Expression = "";
    }

    private void OnClearLast()
    {
        if (Expression.Length > 0)
        {
            Expression = Expression.Remove(Expression.Length - 1);
        }
    }

    private void OnAppendChar(string? value)
    {
        Expression += value;
    }

    public void Dispose()
    {
        _calculator.Dispose();
        GC.SuppressFinalize(this);
    }
}
