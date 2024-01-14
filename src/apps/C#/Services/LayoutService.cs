using CommunityToolkit.Mvvm.ComponentModel;

namespace CalculatorWPF.Services;

public class LayoutService : ObservableObject, ILayoutService
{
    private double _actualWidth = 0;
    public double ActualWidth
    {
        get => _actualWidth;
        set
        {
            if (!SetProperty(ref _actualWidth, value))
            {
                return;
            }

            OnPropertyChanged(nameof(IsBasicLayout));
            OnPropertyChanged(nameof(IsExpandedLayout));

            if (IsExpandedLayout)
            {
                ShowBottomPanel = false;
            }
        }
    }
    public bool IsExpandedLayout => _actualWidth > 500;
    public bool IsBasicLayout => _actualWidth <= 500;

    private bool _showBottomPanel;
    public bool ShowBottomPanel
    {
        get => _showBottomPanel;
        set
        {
            SetProperty(ref _showBottomPanel, value);
        }
    }

    private int _selectedPanelIndex;
    public int SelectedPanelIndex
    {
        get => _selectedPanelIndex;
        set
        {
            SetProperty(ref _selectedPanelIndex, value);
        }
    }
}
