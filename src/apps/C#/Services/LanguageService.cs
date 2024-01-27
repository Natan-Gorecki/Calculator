using CalculatorWPF.Models;
using CalculatorWPF.Resources;
using CommunityToolkit.Mvvm.ComponentModel;
using System.Globalization;

namespace CalculatorWPF.Services;

public class LanguageService : ObservableObject, ILanguageService
{
    private ELanguage _currentLanguage;
    public ELanguage CurrentLanguage
    {
        get => _currentLanguage;
        set
        {
            if (SetProperty(ref _currentLanguage, value))
            {
                OnPropertyChanged(nameof(IsEnglish));
                OnPropertyChanged(nameof(IsPolish));
                LocalizedResources.Instance.CurrentCulture = GetCultureInfo();
            }
        }
    }
    public bool IsEnglish => CurrentLanguage == ELanguage.English;
    public bool IsPolish => CurrentLanguage == ELanguage.Polish;

    private CultureInfo GetCultureInfo()
    {
        var cultureName = _currentLanguage switch
        {
            ELanguage.Polish => "pl",
            _ => "en"
        };
        return new CultureInfo(cultureName);
    }
}
