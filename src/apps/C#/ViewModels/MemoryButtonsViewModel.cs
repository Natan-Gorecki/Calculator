using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Linq;

namespace CalculatorWPF.ViewModels;

public partial class MemoryButtonsViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    [RelayCommand]
    private void MemoryClear()
    {
        CalculatorService.MemoryEntries.Clear();
    }

    [RelayCommand]
    private void MemoryRestore()
    {
        if (!CalculatorService.MemoryEntries.Any())
        {
            return;
        }

        var number = CalculatorService.MemoryEntries[0].Value.ToString();
        CalculatorService.AppendToExpression(number);
    }

    [RelayCommand]
    private void MemoryAdd()
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

    [RelayCommand]
    private void MemorySubstract()
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

    [RelayCommand]
    private void MemorySave()
    {
        if (!CalculatorService.PerformCalculation(out var result))
        {
            return;
        }

        CalculatorService.MemoryEntries.Insert(0, new CalculationEntry(result));
    }

    [RelayCommand]
    private void ShowBottomPanel()
    {
        LayoutService.SelectedPanelIndex = 1;
        LayoutService.ShowBottomPanel = true;
    }
}
