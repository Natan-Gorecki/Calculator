using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace CalculatorWPF.ViewModels;

public partial class MenuBarViewModel : ObservableObject
{
    public IThemeService ThemeService { get; } = App.Ioc.GetRequiredService<IThemeService>();
    public ILanguageService LanguageService { get; } = App.Ioc.GetRequiredService<ILanguageService>();

    [RelayCommand]
    private void ChangeTheme(ETheme theme)
    {
        ThemeService.CurrentTheme = theme;
    }

    [RelayCommand]
    private void ChangeLanguage(ELanguage language)
    {
        LanguageService.CurrentLanguage = language;
    }
}
