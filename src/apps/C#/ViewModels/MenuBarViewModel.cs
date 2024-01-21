using CalculatorWPF.Models;
using CalculatorWPF.Services;
using CommunityToolkit.Mvvm.Input;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Input;

namespace CalculatorWPF.ViewModels;

public class MenuBarViewModel
{
    public IThemeService ThemeService { get; } = App.Ioc.GetRequiredService<IThemeService>();
    public ILanguageService LanguageService { get; } = App.Ioc.GetRequiredService<ILanguageService>();

    public ICommand ChangeTheme { get; }
    public ICommand ChangeLanguage { get; }
    
    public MenuBarViewModel()
    {
        ChangeTheme = new RelayCommand<ETheme>(OnChangeTheme);
        ChangeLanguage = new RelayCommand<ELanguage>(OnChangeLanguage);
    }

    private void OnChangeTheme(ETheme theme)
    {
        ThemeService.CurrentTheme = theme;
    }

    private void OnChangeLanguage(ELanguage language)
    {
        LanguageService.CurrentLanguage = language;
    }
}
