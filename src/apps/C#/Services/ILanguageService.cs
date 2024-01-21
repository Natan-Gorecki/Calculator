using CalculatorWPF.Models;

namespace CalculatorWPF.Services;

public interface ILanguageService
{
    ELanguage CurrentLanguage { get; set; }
    bool IsEnglish { get; }
    bool IsPolish { get; }
}
