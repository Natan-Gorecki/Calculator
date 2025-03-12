using System;
using System.Windows;
using System.Windows.Media;

namespace CalculatorWPF.Utils;

internal static class ViewExtensions
{
    public static T? FindParent<T>(this DependencyObject? child)
        where T : FrameworkElement
    {
        var dependencyObject = child;

        while (dependencyObject != null && dependencyObject is not T)
        {
            dependencyObject = VisualTreeHelper.GetParent(dependencyObject);
        }

        return dependencyObject as T;
    }

    public static T? FindChild<T>(this DependencyObject dependencyObject)
        where T : FrameworkElement
    {
        return FindChild<T>(dependencyObject, child => true);
    }

    public static T? FindChild<T>(this DependencyObject dependencyObject, Predicate<T> predicate)
        where T : FrameworkElement
    {
        ArgumentNullException.ThrowIfNull(dependencyObject);

        int childrenCount = VisualTreeHelper.GetChildrenCount(dependencyObject);

        for (int i = 0; i < childrenCount; i++)
        {
            DependencyObject child = VisualTreeHelper.GetChild(dependencyObject, i);

            if (child is T typedChild && predicate(typedChild))
            {
                return typedChild;
            }

            T? foundChild = FindChild<T>(child, predicate);

            if (foundChild != null)
            {
                return foundChild;
            }
        }

        return null;
    }
}
