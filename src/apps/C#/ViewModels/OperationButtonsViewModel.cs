using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace CalculatorWPF.ViewModels;

public partial class OperationButtonsViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();

    [RelayCommand]
    private void AppendChar(string? value)
    {
        CalculatorService.Expression += value;
    }

    [RelayCommand]
    private void Calculate()
    {
        if (CalculatorService.PerformCalculation(out var result))
        {
            CalculatorService.CalculationEntries.Insert(0, new(CalculatorService.Summary, result));
        }
    }
}
