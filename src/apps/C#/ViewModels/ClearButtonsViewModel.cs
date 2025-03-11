using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace CalculatorWPF.ViewModels;

public partial class ClearButtonsViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    [RelayCommand]
    private void ClearEntry()
    {
        CalculatorService.Summary = "";
        CalculatorService.Expression = "";
    }

    [RelayCommand]
    private void ClearAll()
    {
        CalculatorService.Summary = "";
        CalculatorService.Expression = "";
        CalculatorService.CalculationEntries.Clear();
        CalculatorService.MemoryEntries.Clear();
    }

    [RelayCommand]
    private void ClearLast()
    {
        if (CalculatorService.Expression.Length > 0)
        {
            CalculatorService.Expression = CalculatorService.Expression.Remove(CalculatorService.Expression.Length - 1);
        }
    }
}
