using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace CalculatorWPF.Views;

public partial class TitleBar : UserControl
{
    public TitleBar()
    {
        InitializeComponent();
    }

    private void MinimizeButton_Click(object sender, RoutedEventArgs e)
    {
        Window.GetWindow(this).WindowState = WindowState.Minimized;
    }

    private void MaximizeButton_Click(object sender, RoutedEventArgs e)
    {
        Window.GetWindow(this).WindowState = WindowState.Maximized;
    }

    private void RestoreButton_Click(object sender, RoutedEventArgs e)
    {
        Window.GetWindow(this).WindowState = WindowState.Normal;
    }

    private void CloseButton_Click(object sender, RoutedEventArgs e)
    {
        Window.GetWindow(this).Close();
    }

    private void TitleBar_MouseDown(object sender, MouseButtonEventArgs e)
    {
        if (e.ChangedButton != MouseButton.Left)
        {
            return;
        }

        if (e.ClickCount != 2)
        {
            Application.Current.MainWindow.DragMove();
            return;
        }

        var currentState = Window.GetWindow(this).WindowState;
        Window.GetWindow(this).WindowState = currentState == WindowState.Maximized ? WindowState.Normal : WindowState.Maximized;
    }
}
