using CalculatorWPF.Models;
using CommunityToolkit.Mvvm.ComponentModel;

namespace CalculatorWPF.Services;

public partial class ThemeService : ObservableObject, IThemeService
{
    [NotifyPropertyChangedFor(nameof(IsLight))]
    [NotifyPropertyChangedFor(nameof(IsDark))]
    [ObservableProperty]
    private ETheme _currentTheme;

    public bool IsLight => CurrentTheme == ETheme.Light;
    public bool IsDark => CurrentTheme == ETheme.Dark;

    partial void OnCurrentThemeChanged(ETheme value)
    {
        // Update Theme
    }
}
