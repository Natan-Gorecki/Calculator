using System.ComponentModel;

namespace CalculatorWPF.Services;

public interface ILayoutService : INotifyPropertyChanged
{
    double ActualWidth { get; set; }
    bool IsExpandedLayout { get; }
    bool IsBasicLayout { get; }

    bool ShowBottomPanel { get; set; }
    int SelectedPanelIndex { get; set; }
}
