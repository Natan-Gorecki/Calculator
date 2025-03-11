using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MemoryHistoryViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();

    public ICommand MemoryClear { get; }
    public ICommand MemoryAdd { get; }
    public ICommand MemorySubtract { get; }

    public MemoryHistoryViewModel()
    {
        MemoryClear = new RelayCommand<CalculationEntry>(OnMemoryClear);
        MemoryAdd = new RelayCommand<CalculationEntry>(OnMemoryAdd);
        MemorySubtract = new RelayCommand<CalculationEntry>(OnMemorySubtract);
    }

    private void OnMemoryClear(CalculationEntry? entry)
    {
        if (entry is null)
        {
            return;
        }

        CalculatorService.MemoryEntries.Remove(entry);
    }

    private void OnMemoryAdd(CalculationEntry? entry)
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

    private void OnMemorySubtract(CalculationEntry? entry)
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
