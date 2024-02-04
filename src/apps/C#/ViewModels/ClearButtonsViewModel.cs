using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class ClearButtonsViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    public ICommand ClearEntry { get; }
    public ICommand ClearAll { get; }
    public ICommand ClearLast { get; }

    public ClearButtonsViewModel()
    {
        ClearEntry = new RelayCommand(OnClearEntry);
        ClearAll = new RelayCommand(OnClearAll);
        ClearLast = new RelayCommand(OnClearLast);
    }

    private void OnClearEntry()
    {
        CalculatorService.Summary = "";
        CalculatorService.Expression = "";
    }

    private void OnClearAll()
    {
        CalculatorService.Summary = "";
        CalculatorService.Expression = "";
        CalculatorService.CalculationEntries.Clear();
        CalculatorService.MemoryEntries.Clear();
    }

    private void OnClearLast()
    {
        if (CalculatorService.Expression.Length > 0)
        {
            CalculatorService.Expression = CalculatorService.Expression.Remove(CalculatorService.Expression.Length - 1);
        }
    }
}
