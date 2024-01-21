using CalculatorWPF.Models;
using CommunityToolkit.Mvvm.ComponentModel;

namespace CalculatorWPF.Services;

public class ThemeService : ObservableObject, IThemeService
{
    private ETheme _currentTheme;
    public ETheme CurrentTheme
    {
        get => _currentTheme;
        set
        {
            if (SetProperty(ref _currentTheme, value))
            {
                OnPropertyChanged(nameof(IsLight));
                OnPropertyChanged(nameof(IsDark));
                UpdateTheme();
            }
        }
    }
    public bool IsLight => CurrentTheme == ETheme.Light;
    public bool IsDark => CurrentTheme == ETheme.Dark;

    private void UpdateTheme()
    {

    }
}
