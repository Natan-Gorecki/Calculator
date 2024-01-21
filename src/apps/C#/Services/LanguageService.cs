using CalculatorWPF.Models;
using CommunityToolkit.Mvvm.ComponentModel;

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
                UpdateLanguage();
            }
        }
    }
    public bool IsEnglish => CurrentLanguage == ELanguage.English;
    public bool IsPolish => CurrentLanguage == ELanguage.Polish;

    private void UpdateLanguage()
    {

    }
}
