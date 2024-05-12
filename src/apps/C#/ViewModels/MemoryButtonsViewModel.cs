using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Linq;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MemoryButtonsViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    public ICommand MemoryClear { get; }
    public ICommand MemoryRestore { get; }
    public ICommand MemoryAdd { get; }
    public ICommand MemorySubstract { get; }
    public ICommand MemorySave { get; }
    public ICommand ShowBottomPanel { get; }

    public MemoryButtonsViewModel()
    {
        MemoryClear = new RelayCommand(OnMemoryClear);
        MemoryRestore = new RelayCommand(OnMemoryRestore);
        MemoryAdd = new RelayCommand(OnMemoryAdd);
        MemorySubstract = new RelayCommand(OnMemorySubstract);
        MemorySave = new RelayCommand(OnMemorySave);
        ShowBottomPanel = new RelayCommand(OnShowBottomPanel);
    }

    private void OnMemoryClear()
    {
        CalculatorService.MemoryEntries.Clear();
    }

    private void OnMemoryRestore()
    {
        if (!CalculatorService.MemoryEntries.Any())
        {
            return;
        }

        var number = CalculatorService.MemoryEntries[0].Value.ToString();
        CalculatorService.AppendToExpression(number);
    }

    private void OnMemoryAdd()
    {
        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        if (!CalculatorService.MemoryEntries.Any())
        {
            CalculatorService.MemoryEntries.Add(new(result));
            return;
        }

        CalculatorService.MemoryEntries[0] = new CalculationEntry(CalculatorService.MemoryEntries[0].Value + result);
    }

    private void OnMemorySubstract()
    {
        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        if (!CalculatorService.MemoryEntries.Any())
        {
            CalculatorService.MemoryEntries.Add(new(-result));
            return;
        }

        CalculatorService.MemoryEntries[0] = new CalculationEntry(CalculatorService.MemoryEntries[0].Value - result);
    }

    private void OnMemorySave()
    {
        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        CalculatorService.MemoryEntries.Insert(0, new CalculationEntry(result));
    }

    private void OnShowBottomPanel()
    {
        LayoutService.SelectedPanelIndex = 1;
        LayoutService.ShowBottomPanel = true;
    }
}
