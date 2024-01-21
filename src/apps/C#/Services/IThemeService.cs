using CalculatorWPF.Models;

namespace CalculatorWPF.Services;

public interface IThemeService
{
    ETheme CurrentTheme { get; set; }
    bool IsLight { get; }
    bool IsDark { get; }
}
