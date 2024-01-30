using CalculatorWPF.Utils;
using CalculatorWPF.ViewModels;
using CalculatorWPF.Views;
using Microsoft.Xaml.Behaviors;
using System.Diagnostics;
using System.Reflection;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
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
        if (AssociatedObject.DataContext is not MainWindowViewModel viewModel)
        {
            return;
        }

        HandleClick(e);
        e.Handled = true;
    }

    private Task HandleClick(KeyEventArgs e)
    {
        var parentControl = AssociatedObject.FindChild<OperationButtonsControl>();
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
                Key.D6 => parentControl?.exponentiationButton,
                Key.D8 => parentControl?.multiplyButton,
                Key.D9 => parentControl?.openBracketButton,
                Key.D0 => parentControl?.closeBracketButton,
                Key.OemPlus => parentControl?.addButton,
                _ => null
            };
            return PerformClick(button);
        }

        button = e.Key switch
        {
            Key.D0 or Key.NumPad0 => parentControl?.zeroButton,
            Key.D1 or Key.NumPad1 => parentControl?.oneButton,
            Key.D2 or Key.NumPad2 => parentControl?.twoButton,
            Key.D3 or Key.NumPad3 => parentControl?.threeButton,
            Key.D4 or Key.NumPad4 => parentControl?.fourButton,
            Key.D5 or Key.NumPad5 => parentControl?.fiveButton,
            Key.D6 or Key.NumPad6 => parentControl?.sixButton,
            Key.D7 or Key.NumPad7 => parentControl?.sevenButton,
            Key.D8 or Key.NumPad8 => parentControl?.eightButton,
            Key.D9 or Key.NumPad9 => parentControl?.nineButton,
            Key.Decimal or Key.OemComma or Key.OemPeriod => parentControl?.dotButton,
            Key.Add => parentControl?.addButton,
            Key.Subtract or Key.OemMinus => parentControl?.subtractButton,
            Key.Multiply => parentControl?.multiplyButton,
            Key.Divide or Key.OemQuestion => parentControl?.divideButton,
            Key.Enter or Key.OemPlus => parentControl?.calculateButton,
            Key.Back => AssociatedObject.clearLastButton,
            Key.Delete => AssociatedObject.clearEntryButton,
            Key.Escape => AssociatedObject.clearAllButton,
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

        setIsPressedMethod.Invoke(button, new object[] { true });
        await Task.Delay(100);
        setIsPressedMethod.Invoke(button, new object[] { false });
    }
}
