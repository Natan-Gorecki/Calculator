using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace CalculatorWPF.ViewModels;

public partial class MemoryHistoryViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();

    [RelayCommand]
    private void MemoryClear(CalculationEntry? entry)
    {
        if (entry is null)
        {
            return;
        }

        CalculatorService.MemoryEntries.Remove(entry);
    }

    [RelayCommand]
    private void MemoryAdd(CalculationEntry? entry)
    {
        if (entry is null)
        {
            return;
        }

        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        var index = CalculatorService.MemoryEntries.IndexOf(entry);
        CalculatorService.MemoryEntries[index] = new CalculationEntry(entry.Value + result);
    }

    [RelayCommand]
    private void MemorySubtract(CalculationEntry? entry)
    {
        if (entry is null)
        {
            return;
        }

        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        var index = CalculatorService.MemoryEntries.IndexOf(entry);
        CalculatorService.MemoryEntries[index] = new CalculationEntry(entry.Value - result);
    }
}
