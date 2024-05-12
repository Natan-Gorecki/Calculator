using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class OperationButtonsViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ICommand AppendChar { get; }
    public ICommand Calculate { get; }

    public OperationButtonsViewModel()
    {
        AppendChar = new RelayCommand<string>(OnAppendChar);
        Calculate = new RelayCommand(OnCalculate);
    }

    private void OnAppendChar(string? value)
    {
        CalculatorService.Expression += value;
    }

    private void OnCalculate()
    {
        if (CalculatorService.PerformCalculation(out var result))
        {
            CalculatorService.CalculationEntries.Insert(0, new(CalculatorService.Summary, result));
        }
    }
}
