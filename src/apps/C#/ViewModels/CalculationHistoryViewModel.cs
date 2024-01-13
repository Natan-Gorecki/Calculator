using CalculatorWPF.Services;

namespace CalculatorWPF.ViewModels;

public class CalculationHistoryViewModel
{
    public ICalculatorService CalculatorService { get; } = App.Ioc.GetRequiredService<ICalculatorService>();
}
