using CalculatorWPF.Models;
using CalculatorWPF.Resources;
using CommunityToolkit.Mvvm.ComponentModel;
using System.Globalization;

namespace CalculatorWPF.Services;

public partial class LanguageService : ObservableObject, ILanguageService
{
    [NotifyPropertyChangedFor(nameof(IsEnglish))]
    [NotifyPropertyChangedFor(nameof(IsPolish))]
    [ObservableProperty]
    private ELanguage _currentLanguage;

    public bool IsEnglish => CurrentLanguage == ELanguage.English;
    public bool IsPolish => CurrentLanguage == ELanguage.Polish;

    partial void OnCurrentLanguageChanged(ELanguage value)
    {
        var cultureName = CurrentLanguage switch
        {
            ELanguage.Polish => "pl",
            _ => "en"
        };
        LocalizedResources.Instance.CurrentCulture = new CultureInfo(cultureName);
    }
}
