using System;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace UnlockCode_Calculator.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private void AdbCalc(object sender, RoutedEventArgs args)
    {
        string? code = Adb.Text;
        if (code == null)
        {
            return;
        }

        if ((code.Length <= 8) || (code.Length>11))
        {
            return;
        }
        Adb.Text = CAdb(code);
    }

    string CAdb(string code)
    {
        return A(B(code));
    }

    private string A(string code)
    {
        int i = int.Parse(code.Substring(0, 2));
        int i2 = int.Parse(code.Substring(2, 2));
        int i3 = int.Parse(code.Substring(4, 2));
        int i4 = int.Parse(code.Substring(6, 2));
        int i5 = int.Parse(code.Substring(8));
        int i6 = i4 ^ i3;
        int i7 = i5 ^ i3;
        int i8 = i3 ^ (i6 + i7);
        int i9 = i ^ i7;
        int i10 = i2 ^ i7;
        return i9.ToString().PadLeft(2, '0') + i10.ToString().PadLeft(2, '0') + i6.ToString().PadLeft(2, '0') +
               i7.ToString().PadLeft(2, '0') + i8.ToString();
    }
    private string B(string code)
    {
        int i = int.Parse(code.Substring(0, 2));
        int i2 = int.Parse(code.Substring(2, 2));
        int i3 = int.Parse(code.Substring(4, 2));
        int i4 = int.Parse(code.Substring(6, 2));
        int i5 = int.Parse(code.Substring(8));
        int i6 = i5 ^ (i3 + i4);
        int i7 = i4 ^ i6;
        int i8 = i3 ^ i6;
        int i9 = i ^ i6;
        int i10 = i2 ^ i6;
        return i9.ToString().PadLeft(2, '0') + i10.ToString().PadLeft(2, '0') + i8.ToString().PadLeft(2, '0') +
               i7.ToString().PadLeft(2, '0') + i6.ToString();
    }

    private string C(string code)
    {
        int i = int.Parse(code.Substring(0, 2));
        int i2 = int.Parse(code.Substring(2, 2));
        int i3 = int.Parse(code.Substring(4));
        int i5 = i3 ^ (i + i2);
        int i6 = i ^ i5;
        int i4 = i2 ^ i5;
        return i6.ToString().PadLeft(2, '0') + i4.ToString().PadLeft(2, '0')  + i5.ToString();
    }

    private string D(string code)
    {
        int i = int.Parse(code.Substring(0, 2));
        int i2 = int.Parse(code.Substring(2, 2));
        int i3 = int.Parse(code.Substring(4));
        int i5 = i2 ^ i;
        int i6 = i3 ^ i;
        int i4 = i ^ (i5 + i6);
        return i5.ToString().PadLeft(2, '0') + i6.ToString().PadLeft(2, '0')  + i4.ToString();
    }

    string CSelfTest(string code)
    {
        return D(C(code));
    }

    private void SelfTestCalc(object sender, RoutedEventArgs args)
    {
        string? code = SelfTest.Text;
        if (code == null)
        {
            return;
        }

        if ((code.Length <= 4) || (code.Length>11))
        {
            return;
        }
        SelfTest.Text = CSelfTest(code);
    }
}