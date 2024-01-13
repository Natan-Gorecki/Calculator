using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.ObjectModel;
using System.Windows.Input;
using System.Windows.Navigation;

namespace CalculatorWPF.ViewModels;

public class MemoryHistoryViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();

    public ICommand MemoryClear { get; }
    public ICommand MemoryAdd { get; }
    public ICommand MemorySubtract { get; }

    public MemoryHistoryViewModel()
    {
        MemoryClear = new RelayCommand<MemoryEntry>(OnMemoryClear);
        MemoryAdd = new RelayCommand<MemoryEntry>(OnMemoryAdd);
        MemorySubtract = new RelayCommand<MemoryEntry>(OnMemorySubtract);
    }

    private void OnMemoryClear(MemoryEntry? entry)
    {
        if (entry is null)
        {
            return;
        }

        CalculatorService.MemoryEntries.Remove(entry);
    }

    private void OnMemoryAdd(MemoryEntry? entry)
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
        CalculatorService.MemoryEntries[index] = new MemoryEntry
        {
            Value = entry.Value + result
        };
    }

    private void OnMemorySubtract(MemoryEntry? entry)
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
        CalculatorService.MemoryEntries[index] = new MemoryEntry
        {
            Value = entry.Value - result
        };
    }
}
