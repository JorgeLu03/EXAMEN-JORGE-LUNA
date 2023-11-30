#include <windows.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInstGlob = 0;
struct eventos {
    char fecha[100];
    char hora[100];
    char auditorio[50];
    char artista[50];
    char lugar[50];
    int numE;
    eventos* ant;
    eventos* sig;
};


eventos* inicio, * aux, * fin = NULL;
char fecha1[100] = { 0 }; char hora1[100]; char artista1[50]; char auditorio1[50]; char lugar1[50]; int num;
char fecha2[100] = { 0 }; char hora2[100]; char artista2[50]; char contraseña[50] = { 0 }; char auditorio2[50]; char lugar2[50];
eventos* nodo_eventos = new eventos;

LRESULT CALLBACK Login(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PantallaInicio(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Promociones(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hwnd;
    MSG mensaje;
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(DLG_PROMOCIONES), NULL, Promociones);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(DLG_INICIO), NULL, PantallaInicio);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(DLG_LOGIN), NULL, Login);
    ShowWindow(hwnd, SW_SHOWDEFAULT);


    while (TRUE == GetMessage(&mensaje, 0, 0, 0))
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return mensaje.wParam;
}
int totalfinal = 0;
char precio[150] = {};
int res = 0; int subtotal = 0; float total = 0; int recuperar = 0;
int preciO = 1000; int preciO1 = 600; int preciO2 = 300;
int cont = 0; int boletos = 0; int boletos1 = 0;
char UsuarioLog[50] = { "jorge" };

LRESULT CALLBACK Login(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND: {
        if (LOWORD(wParam) == 1003)
        {
            char UsuarioCorrecto[] = "jorge";
            char ContraseñaCorrecta[] = "123";

            GetDlgItemText(hwnd, CBB_USUARIO_LOGIN, UsuarioLog, sizeof(UsuarioLog));
            GetDlgItemText(hwnd, CBB_CONTRA_LOGIN, contraseña, sizeof(contraseña));
            if (strcmp(UsuarioLog, UsuarioCorrecto) == 0 && strcmp(contraseña, ContraseñaCorrecta) == 0) {
                MessageBox(hwnd, "Usuario Correcto", "Aviso", MB_OK | MB_ICONINFORMATION);
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(DLG_INICIO), NULL, PantallaInicio);
            }
            else {
                MessageBox(hwnd, "Usuario Incorrecto", "ERROR", MB_OK | MB_ICONINFORMATION);

            }

        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
LRESULT CALLBACK PantallaInicio(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    char fecha1[] = "29/11/2023";
    char hora1[] = "21:00";
    char auditorio1[] = "Auditorio Citibanamex";
    char artista1[] = "Mora";
    char lugar1[] = "Monterrey";
    int num = 1;

    switch (msg)
    {
    case WM_INITDIALOG: {

        EnableWindow(GetDlgItem(hwnd, BTN_EVENTOS), FALSE);

        SetWindowText(GetDlgItem(hwnd, 1013), artista1);
        SetWindowText(GetDlgItem(hwnd, 1014), fecha1);
        SetWindowText(GetDlgItem(hwnd, 1015), hora1);
        SetWindowText(GetDlgItem(hwnd, 1016), auditorio1);
        SetWindowText(GetDlgItem(hwnd, 1017), lugar1);

        char artista1[] = "Zoé";
        char fecha1[] = "06/12/2023";
        char auditorio1[] = "Estadio Mobil Super";
        char lugar1[] = "Monterrey";
        char hora1[] = "21:30";
        SetWindowText(GetDlgItem(hwnd, 1019), artista1);
        SetWindowText(GetDlgItem(hwnd, 1020), fecha1);
        SetWindowText(GetDlgItem(hwnd, 1021), hora1);
        SetWindowText(GetDlgItem(hwnd, 1022), auditorio1);
        SetWindowText(GetDlgItem(hwnd, 1023), lugar1);

        SetWindowText(GetDlgItem(hwnd, 1027), "1");



    }break;
    case WM_COMMAND: {
  
       
        if (LOWORD(wParam) == BTN_COMPRAR1)
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, BTN_EVENTOS), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }

            for (int i = 1037; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char VIP[150] = "VIP   $1,000";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
   
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "PREFERENTE   $600";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
         
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "LUNETA   $300";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);
            res = 0;
            SetDlgItemInt(hwnd, CBB_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, 1013, artista2, sizeof(artista2));
            GetDlgItemText(hwnd, 1014, fecha2, sizeof(fecha2));
            GetDlgItemText(hwnd, 1015, hora2, sizeof(hora2));
            GetDlgItemText(hwnd, 1016, auditorio2, sizeof(auditorio2));
            GetDlgItemText(hwnd, 1017, lugar2, sizeof(lugar2));
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAR2)
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, BTN_EVENTOS), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1013; i < 1018; i++)
            {
                SetWindowText(GetDlgItem(hwnd, i), " ");

            }

            GetDlgItemText(hwnd, 1019, artista1, sizeof(artista1));
            GetDlgItemText(hwnd, 1020, fecha1, sizeof(fecha1));
            GetDlgItemText(hwnd, 1021, hora1, sizeof(hora1));
            GetDlgItemText(hwnd, 1022, auditorio1, sizeof(auditorio1));
            GetDlgItemText(hwnd, 1023, lugar1, sizeof(lugar1));
            SetWindowText(GetDlgItem(hwnd, 1013), artista1);
            SetWindowText(GetDlgItem(hwnd, 1014), fecha1);
            SetWindowText(GetDlgItem(hwnd, 1015), hora1);
            SetWindowText(GetDlgItem(hwnd, 1016), auditorio1);
            SetWindowText(GetDlgItem(hwnd, 1017), lugar1);

            for (int i = 1037; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char VIP[150] = "VIP   $1,000";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
       
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "PREFERENTE   $600";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
    
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "LUNETA   $300";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);

            res = 0;
            SetDlgItemInt(hwnd, CBB_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, 1013, artista2, sizeof(artista2));
            GetDlgItemText(hwnd, 1014, fecha2, sizeof(fecha2));
            GetDlgItemText(hwnd, 1015, hora2, sizeof(hora2));
            GetDlgItemText(hwnd, 1016, auditorio2, sizeof(auditorio2));
            GetDlgItemText(hwnd, 1017, lugar2, sizeof(lugar2));
        }
        if (LOWORD(wParam == BTN_REALIZARCOMPRA))
        {
            EnableWindow(GetDlgItem(hwnd, BTN_VENTAS), TRUE);
            res = GetDlgItemInt(hwnd, CBB_CANTIDAD, NULL, TRUE);
            boletos = res;
            boletos1 = res;
            if (res == 0) {
                MessageBox(hwnd, "Ingrese la cantidad de boletos", "Advertencia", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                int idx = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETCURSEL, 0, 0);
                int numc = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETITEMDATA, idx, 0);
                recuperar = numc;
                subtotal = numc * res;
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(DLG_PROMOCIONES), NULL, Promociones);
            }


        }
        if (LOWORD(wParam) == BTN_EVENTOS)
        {

            EnableWindow(GetDlgItem(hwnd, BTN_VENTAS), TRUE);
            EnableWindow(GetDlgItem(hwnd, BTN_EVENTOS), FALSE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1028; i < 1042; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char fecha1[] = "29/11/2023";
            char hora1[] = "21:00";
            char artista1[] = "Mora";
            char auditorio1[] = "Auditorio Citibanamex";
            char lugar1[] = "Monterrey";

            SetWindowText(GetDlgItem(hwnd, 1013), artista1);
            SetWindowText(GetDlgItem(hwnd, 1014), fecha1);
            SetWindowText(GetDlgItem(hwnd, 1015), hora1);
            SetWindowText(GetDlgItem(hwnd, 1016), auditorio1);
            SetWindowText(GetDlgItem(hwnd, 1017), lugar1);
        }
        if (LOWORD(wParam) == BTN_VENTAS)
        {
            if (cont == 1 || cont == 2) {
                for (int i = 1018; i < 1042; i++)
                {
                    ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
                }
                EnableWindow(GetDlgItem(hwnd, BTN_EVENTOS), TRUE);
                EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
                EnableWindow(GetDlgItem(hwnd, BTN_VENTAS), FALSE);
                SetWindowText(GetDlgItem(hwnd, 1013), artista2);
                SetWindowText(GetDlgItem(hwnd, 1014), fecha2);
                SetWindowText(GetDlgItem(hwnd, 1015), hora2);
                SetWindowText(GetDlgItem(hwnd, 1016), auditorio2);
                SetWindowText(GetDlgItem(hwnd, 1017), lugar2);


                for (int i = 1059; i < 1064; i++)
                {
                    ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
                }
                SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_BOLETOS, boletos1, TRUE);
                SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_TOTAL, totalfinal, TRUE);
            }
            else if (cont == 0) {
                MessageBox(hwnd, "No ha realizado ninguna compra", "Aviso", MB_OK | MB_ICONINFORMATION);
            }
        }
        if (LOWORD(wParam) == ID_BOTON_SALIR_PI)
        {
            DestroyWindow(hwnd);
            PostQuitMessage(0);
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
char numC[16] = { 0 };
LRESULT CALLBACK Promociones(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG: {

        total = subtotal + (subtotal * 0.16);
        sprintf_s(numC, "%.3f", total);
        SetDlgItemText(hwnd, CBB_TOTALCOMPRA, numC);
        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Ninguno");


        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"2x1");
        int precio3 = 1;
        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), CB_SETITEMDATA, -1, (LPARAM)precio3);
        int precio1 = 2;
        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), CB_SETITEMDATA, 0, (LPARAM)precio1);
        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"20%");
        int precio2 = 3;
        SendMessage(GetDlgItem(hwnd, CMB_DESCUENTO), CB_SETITEMDATA, 0, (LPARAM)precio2);
        SendMessage(GetDlgItem(hwnd, CMB_FORMAPAGO_PROMOCION), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de débito");
        SendMessage(GetDlgItem(hwnd, CMB_FORMAPAGO_PROMOCION), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de crédito");
        SendMessage(GetDlgItem(hwnd, CMB_FORMAPAGO_PROMOCION), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Paypal");
        res = 0;
        SetDlgItemInt(hwnd, CBB_TARJETA_PROMOCION, res, TRUE);
        SetDlgItemInt(hwnd, CBB_TARJETA_PROMOCION, res, TRUE);
        SetDlgItemInt(hwnd, CBB_TARJETA_PROMOCION, res, TRUE);

    }break;
    case WM_COMMAND: {
        if (LOWORD(wParam) == BTN_APPLY)
        {
            int idx = SendDlgItemMessage(hwnd, CMB_DESCUENTO, CB_GETCURSEL, 0, 0);
            int numc = SendDlgItemMessage(hwnd, CMB_DESCUENTO, CB_GETITEMDATA, idx, 0);
            SetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, numc, TRUE);
            if (numc == 1)
            {
                if (boletos % 2 == 0)
                {
                    boletos = boletos / 2;
                    subtotal = boletos * recuperar;
                    total = subtotal + (subtotal * 0.16);
                    sprintf_s(numC, "%.3f", total);
                    SetDlgItemText(hwnd, CBB_TOTALCOMPRA, numC);
                }

            }
            if (numc == 3)
            {
                total = subtotal - (subtotal * 0.20);
                sprintf_s(numC, "%.3f", total);
                SetDlgItemText(hwnd, CBB_TOTALCOMPRA, numC);
            }
        }
        if (LOWORD(wParam) == BTN_ACEPTAR_PROMOCION)
        {
            totalfinal = total;
            cont = 1;
            int res3 = GetDlgItemInt(hwnd, ID_EDIT_TARJETA_COMPRA, NULL, TRUE);
            int res1 = GetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, NULL, TRUE);
            if (res3 == 0 || res1 == 0) {
                MessageBox(hwnd, "Ingrese todos los datos", "Advertencia", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(DLG_INICIO), NULL, PantallaInicio);
            }

        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}

void  agregar_evento(eventos* nuevo) {
    if (inicio == NULL) {
        inicio = new eventos;
        aux = inicio;

        aux->sig = NULL;
        aux->ant = NULL;

        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->artista, nuevo->artista);
        strcpy_s(aux->auditorio, nuevo->auditorio);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->numE = nuevo->numE;

    }
    else {
        aux = inicio;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new eventos;
        aux->sig->sig = NULL;
        aux->sig->ant = aux;
        aux = aux->sig;
        fin = aux;
        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->artista, nuevo->artista);
        strcpy_s(aux->auditorio, nuevo->auditorio);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->numE = nuevo->numE;
    }
}