using CalculatorWPF.Utils;
using CalculatorWPF.ViewModels;
using CalculatorWPF.Views;
using Microsoft.Xaml.Behaviors;
using System.Reflection;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace CalculatorWPF.Behaviors;

internal class HandleKeyboardEventsBehavior : Behavior<MainWindow>
{
    protected override void OnAttached()
    {
        AssociatedObject.PreviewKeyDown += MainWindow_PreviewKeyDown;
    }

    protected override void OnDetaching()
    {
        AssociatedObject.PreviewKeyDown -= MainWindow_PreviewKeyDown;
    }

    private void MainWindow_PreviewKeyDown(object sender, KeyEventArgs e)
    {
        if (AssociatedObject.DataContext is not MainWindowViewModel)
        {
            return;
        }

        HandleClick(e);
        e.Handled = true;
    }

    private Task HandleClick(KeyEventArgs e)
    {
        var operationButtonsControl = AssociatedObject.FindChild<OperationButtonsControl>();
        var clearButtonsControl = AssociatedObject.FindChild<ClearButtonsControl>();
        Button? button;

        var isShiftPressed = Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift);
        var isAltPressed = Keyboard.IsKeyDown(Key.LeftAlt) || Keyboard.IsKeyDown(Key.RightAlt);
        var isCtrlPressed = Keyboard.IsKeyDown(Key.LeftCtrl) || Keyboard.IsKeyDown(Key.RightCtrl);

        if (isAltPressed || isCtrlPressed)
        {
            return Task.CompletedTask;
        }

        if (isShiftPressed)
        {
            button = e.Key switch
            {
                Key.D6 => operationButtonsControl?.exponentiationButton,
                Key.D8 => operationButtonsControl?.multiplyButton,
                Key.D9 => operationButtonsControl?.openBracketButton,
                Key.D0 => operationButtonsControl?.closeBracketButton,
                Key.OemPlus => operationButtonsControl?.addButton,
                _ => null
            };
            return PerformClick(button);
        }

        button = e.Key switch
        {
            Key.D0 or Key.NumPad0 => operationButtonsControl?.zeroButton,
            Key.D1 or Key.NumPad1 => operationButtonsControl?.oneButton,
            Key.D2 or Key.NumPad2 => operationButtonsControl?.twoButton,
            Key.D3 or Key.NumPad3 => operationButtonsControl?.threeButton,
            Key.D4 or Key.NumPad4 => operationButtonsControl?.fourButton,
            Key.D5 or Key.NumPad5 => operationButtonsControl?.fiveButton,
            Key.D6 or Key.NumPad6 => operationButtonsControl?.sixButton,
            Key.D7 or Key.NumPad7 => operationButtonsControl?.sevenButton,
            Key.D8 or Key.NumPad8 => operationButtonsControl?.eightButton,
            Key.D9 or Key.NumPad9 => operationButtonsControl?.nineButton,
            Key.Decimal or Key.OemComma or Key.OemPeriod => operationButtonsControl?.dotButton,
            Key.Add => operationButtonsControl?.addButton,
            Key.Subtract or Key.OemMinus => operationButtonsControl?.subtractButton,
            Key.Multiply => operationButtonsControl?.multiplyButton,
            Key.Divide or Key.OemQuestion => operationButtonsControl?.divideButton,
            Key.Enter or Key.OemPlus => operationButtonsControl?.calculateButton,
            Key.Back => clearButtonsControl?.clearLastButton,
            Key.Delete => clearButtonsControl?.clearEntryButton,
            Key.Escape => clearButtonsControl?.clearAllButton,
            _ => null,
        };
        return PerformClick(button);
    }

    private static async Task PerformClick(Button? button)
    {
        if (button is null)
        {
            return;
        }

        if (!button.Command.CanExecute(button.CommandParameter))
        {
            return;
        }

        button.Command.Execute(button.CommandParameter);

        var setIsPressedMethod = typeof(Button).GetMethod("set_IsPressed", BindingFlags.Instance | BindingFlags.NonPublic);

        if (setIsPressedMethod is null)
        {
            return;
        }

        setIsPressedMethod.Invoke(button, [true]);
        await Task.Delay(100);
        setIsPressedMethod.Invoke(button, [false]);
    }
}
