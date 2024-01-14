using CalculatorWPF.Services;

namespace CalculatorWPF.ViewModels;

public class HistoryExpanderViewModel
{
    public ILayoutService LayoutService { get; } = App.Ioc.GetRequiredService<ILayoutService>();
}
