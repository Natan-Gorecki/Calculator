using CalculatorWPF.ViewModels;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace CalculatorWPF.Views;

public partial class HistoryExpander : UserControl
{
    public HistoryExpander()
    {
        InitializeComponent();
        Loaded += HistoryExpander_Loaded;
    }

    private void HistoryExpander_Loaded(object sender, RoutedEventArgs e)
    {
        var parentWindow = Window.GetWindow(this);
        if (parentWindow != null)
        {
            parentWindow.MouseUp += Window_MouseUp;
        }
    }

    private void Window_MouseUp(object sender, MouseButtonEventArgs e)
    {
        if (Visibility != Visibility.Visible)
        {
            return;
        }

        if (DataContext is not HistoryExpanderViewModel viewModel)
        {
            return;
        }

        if (ClickedOutsideTabControl(e))
        {
            viewModel.LayoutService.ShowBottomPanel = false;
        }
    }

    private bool ClickedOutsideTabControl(MouseButtonEventArgs e)
    {
        var pos = e.GetPosition(tabControl);
        return pos.X < 0 || pos.X > tabControl.ActualWidth ||
               pos.Y < 0 || pos.Y > tabControl.ActualHeight;
    }
}
