using CalculatorCLI;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MainWindowViewModel : ObservableObject, IDisposable
{
    private readonly Calculator _calculator = new();

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

    private string _output = string.Empty;
    public string Output
    {
        get => _output;
        set
        {
            _output = value;
            OnPropertyChanged(nameof(Output));
        }
    }

    public ICommand Calculate { get; }

    public MainWindowViewModel()
    {
        _calculator = new Calculator();
        Calculate = new RelayCommand(OnCalculate);
    }

    private void OnCalculate()
    {
        try
        {
            Output = _calculator.Calculate(Expression).ToString();
        }
        catch (ExpressionException ex)
        {
            Output = $"Error: {ex.Message} Position: {ex.Position}('{ex.Expression[ex.Position]}').";
        }
    }

    public void Dispose()
    {
        _calculator.Dispose();
        GC.SuppressFinalize(this);
    }
}
