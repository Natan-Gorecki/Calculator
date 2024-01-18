using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MainWindowViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    public ICommand ClearEntry { get; }
    public ICommand ClearAll { get; }
    public ICommand ClearLast { get; }
    public ICommand ShowBottomPanel { get; }

    public MainWindowViewModel()
    {
        ClearEntry = new RelayCommand(OnClearEntry);
        ClearAll = new RelayCommand(OnClearAll);
        ClearLast = new RelayCommand(OnClearLast);
        ShowBottomPanel = new RelayCommand(OnShowBottomPanel);
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

    private void OnShowBottomPanel()
    {
        LayoutService.SelectedPanelIndex = 0;
        LayoutService.ShowBottomPanel = true;
    }
}
