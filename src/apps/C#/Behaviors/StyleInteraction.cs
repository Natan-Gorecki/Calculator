using Microsoft.Xaml.Behaviors;
using System.Collections.Generic;
using System.Windows;

namespace CalculatorWPF.Behaviors;

internal class BehaviorCollection : List<Behavior>
{
}

internal static class StyleInteraction
{
    public static readonly DependencyProperty BehaviorsProperty = DependencyProperty.RegisterAttached(
        nameof(Behaviors),
        typeof(BehaviorCollection),
        typeof(StyleInteraction),
        new UIPropertyMetadata(null, BehaviorsPropertyChangedHandler)
    );

    public static BehaviorCollection GetBehaviors(DependencyObject dependencyObject)
    {
        return (BehaviorCollection)dependencyObject.GetValue(BehaviorsProperty);
    }

    public static void SetBehaviors(DependencyObject dependencyObject, BehaviorCollection value)
    {
        dependencyObject.SetValue(BehaviorsProperty, value);
    }

    private static void BehaviorsPropertyChangedHandler(DependencyObject dependencyObject, DependencyPropertyChangedEventArgs e)
    {
        var behaviors = Interaction.GetBehaviors(dependencyObject);
        (e.NewValue as BehaviorCollection)?.ForEach(x => behaviors.Add(x));
        (e.OldValue as BehaviorCollection)?.ForEach(x => behaviors.Remove(x));
    }
}
