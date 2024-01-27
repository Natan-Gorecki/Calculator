using System.Windows.Data;

namespace CalculatorWPF.Resources;

public class LocalizedResource : Binding
{
    public LocalizedResource(string name) : base($"[{name}]")
    {
        Mode = BindingMode.OneWay;
        Source = LocalizedResources.Instance;
    }
}
