using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MainWindowViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();

    public ICommand Calculate { get; }
    public ICommand ClearEntry { get; }
    public ICommand ClearAll { get; }
    public ICommand ClearLast { get; }
    public ICommand AppendChar { get; }

    public MainWindowViewModel()
    {
        Calculate = new RelayCommand(OnCalculate);
        ClearEntry = new RelayCommand(OnClearEntry);
        ClearAll = new RelayCommand(OnClearAll);
        ClearLast = new RelayCommand(OnClearLast);
        AppendChar = new RelayCommand<string>(OnAppendChar);
    }

    private void OnCalculate()
    {
        if (CalculatorService.PerformCalculation(out var result))
        {
            CalculatorService.CalculationEntries.Insert(0, new()
            {
                Expression = CalculatorService.Summary,
                Result = result
            });
        }
    }

    private void OnClearEntry()
    {
        CalculatorService.Expression = "";
    }

    private void OnClearAll()
    {
        CalculatorService.Summary = "";
        CalculatorService.Expression = "";
        CalculatorService.CalculationEntries.Clear();
    }

    private void OnClearLast()
    {
        if (CalculatorService.Expression.Length > 0)
        {
            CalculatorService.Expression = CalculatorService.Expression.Remove(CalculatorService.Expression.Length - 1);
        }
    }

    private void OnAppendChar(string? value)
    {
        CalculatorService.Expression += value;
    }
}
