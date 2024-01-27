using System.ComponentModel;
using System.Globalization;
using System.Resources;

namespace CalculatorWPF.Resources;

public class LocalizedResources : INotifyPropertyChanged
{
    private static readonly LocalizedResources _instance = new();
    public static LocalizedResources Instance => _instance;

    private readonly ResourceManager _resourceManager = Resources.ResourceManager;
    private CultureInfo? _currentCulture = null;

    public string? this[string key] => _resourceManager.GetString(key, _currentCulture);

    public CultureInfo? CurrentCulture
    {
        get => _currentCulture;
        set
        {
            if (_currentCulture != value)
            {
                _currentCulture = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(string.Empty));
            }
        }
    }

    public event PropertyChangedEventHandler? PropertyChanged;
}
