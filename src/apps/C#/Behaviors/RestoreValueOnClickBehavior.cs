using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CalculatorWPF.Utils;
using Microsoft.Xaml.Behaviors;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace CalculatorWPF.Behaviors;

internal class RestoreValueOnClickBehavior : Behavior<ListViewItem>
{
    protected override void OnAttached()
    {
        AssociatedObject.PreviewMouseDown += ListView_PreviewMouseDown;
    }

    protected override void OnDetaching()
    {
        AssociatedObject.PreviewMouseDown -= ListView_PreviewMouseDown;
    }

    private void ListView_PreviewMouseDown(object sender, MouseButtonEventArgs e)
    {
        if (e.OriginalSource is not DependencyObject dependencyObject)
        {
            return;
        }

        var buttonParent = dependencyObject.FindParent<Button>();
        if (buttonParent is not null)
        {
            return;
        }

        if ((sender as ListViewItem)?.DataContext is not CalculationEntry calculationEntry)
        {
            return;
        }

        var listView = dependencyObject.FindParent<ListView>();
        if (listView is null)
        {
            return;
        }

        var calculatorService = ExtractCalculatorService(listView);
        if (calculatorService is null)
        {
            return;
        }

        e.Handled = true;
        calculatorService.AppendToExpression(calculationEntry.Value.ToString());
    }

    private static ICalculatorService? ExtractCalculatorService(ListView listView)
    {
        var dataContextType = listView.DataContext?.GetType();

        var calculatorServiceProperty = dataContextType?.GetProperty("CalculatorService");
        if (calculatorServiceProperty is null)
        {
            return null;
        }

        return calculatorServiceProperty.GetValue(listView.DataContext) as ICalculatorService;
    }
}
