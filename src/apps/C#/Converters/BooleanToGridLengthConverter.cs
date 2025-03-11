using System;
using System.Globalization;
using System.Windows;
using System.Windows.Data;

namespace CalculatorWPF.Converters;

public class BooleanToGridLengthConverter : IValueConverter
{
    private readonly static GridLength DefaultLength = new(0, GridUnitType.Pixel);

    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        if (value is not bool booleanValue ||
            parameter is not string stringParameter)
        {
            return DefaultLength;
        }

        if (booleanValue && TryParseGridLength(stringParameter, out var gridLength))
        {
            return gridLength;
        }

        return DefaultLength;
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }

    private static bool TryParseGridLength(string stringValue, out GridLength gridLength)
    {
        gridLength = DefaultLength;

        if (stringValue.Equals("Auto", StringComparison.OrdinalIgnoreCase))
        {
            gridLength = GridLength.Auto;
            return true;
        }

        if (stringValue.EndsWith("*"))
        {
            double starCount = 1;
            if (stringValue.Length > 1 && !double.TryParse(stringValue.AsSpan(0, stringValue.Length - 1), out starCount))
            {
                return false;
            }

            gridLength  = new GridLength(starCount, GridUnitType.Star);
            return true;
        }

        if (double.TryParse(stringValue, out var pixelValue))
        {
            gridLength = new GridLength(pixelValue, GridUnitType.Pixel);
            return true;
        }

        return false;
    }
}
