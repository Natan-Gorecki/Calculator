using CalculatorWPF.ViewModels;
using System.Windows;

namespace CalculatorWPF.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        SizeChanged += MainWindow_SizeChanged;
    }

    private void MainWindow_SizeChanged(object sender, SizeChangedEventArgs e)
    {
        if (DataContext is MainWindowViewModel viewModel)
        {
            viewModel.LayoutService.ActualWidth = ActualWidth;
        }
    }
}
