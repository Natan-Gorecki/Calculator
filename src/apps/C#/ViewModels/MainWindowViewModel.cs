using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MainWindowViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    public ICommand ShowBottomPanel { get; }

    public MainWindowViewModel()
    {
        ShowBottomPanel = new RelayCommand(OnShowBottomPanel);
    }

    private void OnShowBottomPanel()
    {
        LayoutService.SelectedPanelIndex = 0;
        LayoutService.ShowBottomPanel = true;
    }
}
