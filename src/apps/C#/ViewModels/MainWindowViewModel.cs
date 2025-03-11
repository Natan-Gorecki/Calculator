using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace CalculatorWPF.ViewModels;

public partial class MainWindowViewModel : ObservableObject
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();

    [RelayCommand]
    private void ShowBottomPanel()
    {
        LayoutService.SelectedPanelIndex = 0;
        LayoutService.ShowBottomPanel = true;
    }
}
