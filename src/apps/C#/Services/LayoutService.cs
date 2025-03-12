using CommunityToolkit.Mvvm.ComponentModel;

namespace CalculatorWPF.Services;

public partial class LayoutService : ObservableObject, ILayoutService
{
    [NotifyPropertyChangedFor(nameof(IsBasicLayout))]
    [NotifyPropertyChangedFor(nameof(IsExpandedLayout))]
    [ObservableProperty]
    private double _actualWidth = 0;

    [ObservableProperty]
    private bool _showBottomPanel;

    [ObservableProperty]
    private int _selectedPanelIndex;

    public bool IsExpandedLayout => ActualWidth > 500;
    public bool IsBasicLayout => ActualWidth <= 500;

    partial void OnActualWidthChanged(double value)
    {
        if (IsExpandedLayout)
        {
            ShowBottomPanel = false;
        }
    }
}
