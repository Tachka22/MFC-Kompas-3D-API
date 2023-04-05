// MFCAppKompasDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCAppKompas.h"
#include "MFCAppKompasDlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "D:\Компас\SDK\Include\ksConstants3D.h" //yout path
#include "D:\Компас\SDK\Include\ksConstants.h" //yout path
#include<string>




#ifdef _DEBUGы
#define new DEBUG_NEW
#endif

#define PI 4*atan(1)

#pragma once

#import "D:\Компас\SDK\lib\kAPI5.tlb" //yout path
using namespace Kompas6API5;

KompasObjectPtr pKompasApp5;

ksPartPtr pPart;// = PartDoc->GetTopPart();
ksDocument3DPtr pDoc;


// Диалоговое окно CAboutDlg используется для описания сведений о приложении
class Point
{
public:
	Point();
	Point(double a, double b);
	~Point();
	double x;
	double y;
private:

};

Point::Point()
{
}
Point::Point(double a, double b)
{
	x = a;
	y = b;

}
Point::~Point()
{
}
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	Point point;
// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCAppKompasDlg



CMFCAppKompasDlg::CMFCAppKompasDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPKOMPAS_DIALOG, pParent)
	, m_Dup(135)
	, m_Ddown(45)
	, m_L(110)
	, m_L1(138)
	, m_L2(48)
	, m_L3(25)
	, m_D1(70)
	, m_B1(32)
	, m_B(9)
	, m_Dzv(130)
	, m_dzv(56)
	, m_Hzv(25)
	, m_Bzv(18.5)
	, m_b(14)
	, m_dt1(49.9)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppKompasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Dup);
	DDX_Text(pDX, IDC_EDIT3, m_Ddown);
	DDX_Text(pDX, IDC_EDIT4, m_L);
	DDX_Text(pDX, IDC_EDIT5, m_L1);
	DDX_Text(pDX, IDC_EDIT1, m_L2);
	DDX_Text(pDX, IDC_EDIT6, m_L3);
	DDX_Text(pDX, IDC_EDIT7, m_D1);
	DDX_Text(pDX, IDC_EDIT8, m_B1);
	DDX_Text(pDX, IDC_EDIT9, m_B);
	DDX_Text(pDX, IDC_EDIT10, m_Dzv);
	DDX_Text(pDX, IDC_EDIT11, m_dzv);
	DDX_Text(pDX, IDC_EDIT12, m_Hzv);
	DDX_Text(pDX, IDC_EDIT13, m_Bzv);
	DDX_Text(pDX, IDC_EDIT14, m_b);
	DDX_Text(pDX, IDC_EDIT15, m_dt1);
}

BEGIN_MESSAGE_MAP(CMFCAppKompasDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCAppKompasDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCAppKompasDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCAppKompasDlg

BOOL CMFCAppKompasDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCAppKompasDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCAppKompasDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCAppKompasDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



bool CMFCAppKompasDlg::CheckData()
{
	if (!UpdateData()) 
		return false;
	else
		return true;
}

void CMFCAppKompasDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CMFCAppKompasDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений

	BeginWaitCursor();

	if (!CheckData())
		return;

	CComPtr<IUnknown> pKompasAppUnk = nullptr;
	if (!pKompasApp5)
	{
		// Получаем CLSID для Компас
		CLSID InvAppClsid;
		HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
		if (FAILED(hRes)) {
			pKompasApp5 = nullptr;
			return;
		}

		// Проверяем есть ли запущенный экземпляр Компас
		//если есть получаем IUnknown
		hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
		if (FAILED(hRes)) {
			// Приходится запускать Компас самим так как работающего нет
			// Также получаем IUnknown для только что запущенного приложения Компас
			TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
			hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}
		}

		// Получаем интерфейс приложения Компас
		hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
		if (FAILED(hRes)) {
			return;
		}
	}

	//делаем компс видимым
	pKompasApp5->Visible = true;
	

 #pragma region Полумуфта

	pDoc = pKompasApp5->Document3D();//получили инитерфейс трёхмерного документа

	pDoc->Create(false, true);//создаём пустой элемент (деталь/сборка)

	pPart = pDoc->GetPart(pTop_Part);//получаем указатель на интерфейс компонента в сборк
	//pTop_Part  – верхний компонент, в состав которого входит или новый, или редактируемый, или указанный компонент;

	ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);
	//NewEntity-создаёт интерфейс нового трёхмерного объекта и возвращает указатель на него
	//o3d_sketch - эскиз трёхмерной операции

	ksEntityPtr pFillet = pPart->NewEntity(o3d_fillet);

	ksFilletDefinitionPtr pFilletDef = pFillet->GetDefinition();

	ksEntityCollectionPtr fl = pFilletDef->array();

	ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();
	//GetDefinition() - возвращает указатель на интерфейст объекта, создаваемогг системой в трёхмерном документе
	//начало координат + три плоскости 

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));//выбираем плоскость

	pSketch->Create();//создаём эскиз

	ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();
	//BeginEdit() - режим редактирования

	//эскиз вала

	double point[10][10];

	point[0][0] = 0;//x
	point[0][1] = 0; //y

	point[1][0] = m_L;//x
	point[1][1] = 0; //y

	point[2][0] = m_L;//x
	point[2][1] = m_D1 / 2;//y

	point[3][0] = m_L2 - m_L3;//x
	point[3][1] = m_D1 / 2; //y

	point[4][0] = m_L2 - m_L3;//x
	point[4][1] = m_Dup / 2;

	point[5][0] = 0;//x
	point[5][1] = m_Dup / 2;//y

	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[4][0], point[4][1], 1);
	p2DDoc->ksLineSeg(point[4][0], point[4][1], point[5][0], point[5][1], 1);
	p2DDoc->ksLineSeg(point[5][0], point[5][1], point[0][0], point[0][1], 1);

	p2DDoc->ksLineSeg(-10, 0, 10, 0, 3);

	pSketchDef->EndEdit();

	//вращение

	ksEntityPtr pRotate = pPart->NewEntity(o3d_bossRotated);
	ksBossRotatedDefinitionPtr pRotDef = pRotate->GetDefinition();
	pRotDef->SetSketch(pSketch);
	pRotDef->SetSideParam(TRUE, 360);

	pRotate->Create();

	//отверстиеъ
	//эскиз
	ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch1->GetDefinition();
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));
	pSketch1->Create();
	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksCircle(0, 0, m_Ddown / 2.f, 1);

	pSketchDef->EndEdit();

	//вырез
	ksEntityPtr pExtrude = pPart->NewEntity(o3d_cutExtrusion);

	ksCutExtrusionDefinitionPtr pExDef = pExtrude->GetDefinition();
	pExDef->directionType = dtNormal;

	pExDef->SetSketch(pSketch1);
	pExDef->SetSideParam(true, etThroughAll, 0, 0, false);

	pExtrude->Create();

	//уцфаыуепиодтл
	//эскиз
	ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch2->GetDefinition();
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));
	pSketch2->Create();
	p2DDoc = pSketchDef->BeginEdit();

	double point2[5][5];
	point2[0][0] = (m_Dup / 2) * cos(60.f * PI / 180.f);//right up
	point2[0][1] = (m_Dup / 2) * sin(60.f * PI / 180.f);

	point2[1][0] = (m_Dup / 2) * cos(120.f * PI / 180.f);//left up
	point2[1][1] = (m_Dup / 2) * sin(120.f * PI / 180.f);

	point2[2][0] = -(tan(30.f * PI / 180) * m_B1);//left down
	point2[2][1] = m_B1;

	point2[3][0] = tan(30.f * PI / 180) * m_B1;//right up
	point2[3][1] = m_B1;

	point2[4][0] = 0;
	point2[4][1] = m_Dup / 2;

	p2DDoc->ksLineSeg(point2[3][0], point2[3][1], point2[0][0], point2[0][1], 1);

	p2DDoc->ksArcBy3Points(point2[0][0], point2[0][1], point2[4][0], point2[4][1], point2[1][0], point2[1][1], 1);

	p2DDoc->ksLineSeg(point2[1][0], point2[1][1], point2[2][0], point2[2][1], 1);

	p2DDoc->ksLineSeg(point2[2][0], point2[2][1], point2[3][0], point2[3][1], 1);

	pSketchDef->EndEdit();

	//выдавливание
	ksEntityPtr pExtrude1 = pPart->NewEntity(o3d_bossExtrusion);

	ksBossExtrusionDefinitionPtr pExDef1 = pExtrude1->GetDefinition();
	pExDef1->directionType = dtNormal;

	pExDef1->SetSketch(pSketch2);

	pExDef1->SetSideParam(true, etBlind, Otstup, 0, false);

	pExtrude1->Create();

	//смещение плоскости
	ksEntityPtr pPlane1 = pPart->NewEntity(o3d_planeOffset);
	ksPlaneOffsetDefinitionPtr pPlaneDef = pPlane1->GetDefinition();

	pPlaneDef->direction = true;
	pPlaneDef->offset = Otstup;
	pPlaneDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));
	pPlane1->Putname("planePol1");

	pPlane1->Create();


	//зуб
	//эскиз
	ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch3->GetDefinition();
	pSketchDef->SetPlane(pPlane1);
	pSketch3->Create();
	p2DDoc = pSketchDef->BeginEdit();

	double point3[8][8];

	
	double x3 = m_B * sin(-30.f * PI / 180.f);

	double y3 = m_B * cos(-30.f * PI / 180.f);

	double b3 = y3 - (sqrt(3) / 3) * x3;

	double c = (((m_B * 2) * (cos(30.f * PI / 180))) ) ;
	

	double d = m_B * 2;


	point3[0][0] =  (   m_Dup / 2 - c ) * cos(60.f * PI / 180.f);//right up
	point3[0][1] = m_B * 2 + (   m_Dup / 2  -c ) * sin(60.f * PI / 180.f);

	point3[1][0] =   (   m_Dup / 2 -c) * cos(120.f * PI / 180.f);//left up
	point3[1][1] = m_B * 2 + (   m_Dup / 2 -c) * sin(120.f * PI / 180.f);

	point3[2][0] = -(tan(30.f * PI / 180) * (m_B1 - m_B * 2));//left down
	point3[2][1] = m_B * 2 + (m_B1 - m_B * 2);

	point3[3][0] = tan(30.f * PI / 180) * (m_B1 - m_B * 2);//right up
	point3[3][1] = m_B * 2 + (m_B1 - m_B * 2);

	point3[4][0] = 0;
	point3[4][1] = m_Dup / 2;


	p2DDoc->ksLineSeg(point3[3][0], point3[3][1], point3[0][0], point3[0][1], 1);

	p2DDoc->ksArcBy3Points(point3[0][0], point3[0][1], point3[4][0], point3[4][1], point3[1][0], point3[1][1], 1);

	p2DDoc->ksLineSeg(point3[1][0], point3[1][1], point3[2][0], point3[2][1], 1);

	p2DDoc->ksLineSeg(point3[2][0], point3[2][1], point3[3][0], point3[3][1], 1);

	pSketchDef->EndEdit();



	//выдавливание
	ksEntityPtr pExtrude2 = pPart->NewEntity(o3d_bossExtrusion);

	pExDef1 = pExtrude2->GetDefinition();
	pExDef1->directionType = dtNormal;

	pExDef1->SetSketch(pSketch3);

	pExDef1->SetSideParam(true, etBlind, m_L3, 0, false);

	pExtrude2->Create();


	ksEntityPtr pSketch5 = pPart->NewEntity(o3d_sketch);
	pSketchDef = pSketch5->GetDefinition();
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));
	pSketch5->Create();
	p2DDoc = pSketchDef->BeginEdit();
	p2DDoc->ksCircle(0, 0, m_Dup / 2, 1);
	p2DDoc->ksCircle(0, 0, (m_Dup / 2) * 10000, 1);
	pSketchDef->EndEdit();
	ksEntityPtr pExtrude5 = pPart->NewEntity(o3d_cutExtrusion);
	pExDef = pExtrude5->GetDefinition();
	pExDef->directionType = dtReverse;
	pExDef->SetSketch(pSketch5);
	pExDef->SetSideParam(false, etBlind, m_L, 0, false);
	pExtrude5->Create();

	ksEntityCollectionPtr flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();

		if (def->GetOwnerEntity() == pExtrude2)
		{
			if (def->IsPlanar())
			{
				ksEdgeCollectionPtr col = def->EdgeCollection();
				bool flag = false;
				for (int k = 0; k < col->GetCount(); k++)
				{

					ksEdgeDefinitionPtr d = col->GetByIndex(k);

					if (d->IsStraight())
					{
						ksVertexDefinitionPtr p1 = d->GetVertex(true);
						ksVertexDefinitionPtr p2 = d->GetVertex(false);
						double x1, y1, z1;
						double x2, y2, z2;
						double k = m_L1 - m_L - m_L3;
						p1->GetPoint(&x1, &y1, &z1);
						p2->GetPoint(&x2, &y2, &z2);
						if (fabs(x1) <= k) flag = true;
						if (fabs(x1) == m_L3  + k && flag)
						{
								face->Putname("Cylinder4Assembly0");
								face->Update();
								break;
							
						}

					}
				}
			}
		}
	}

	


	//массив
	ksEntityPtr pCircCopy = pPart->NewEntity(o3d_circularCopy);
	ksCircularCopyDefinitionPtr pCircDef = pCircCopy->GetDefinition();

	pCircDef->Putcount2(3);//кол во

	pCircDef->SetAxis(pPart->GetDefaultEntity(o3d_axisOX));//ось


	fl = pCircDef->GetOperationArray();
	fl->Clear();

	fl->Add(pExtrude1);
	fl->Add(pExtrude2);
	fl->Add(pExtrude5);

	pCircCopy->Create();





	//шл
	//смещение плоскости
	ksEntityPtr pPlane2 = pPart->NewEntity(o3d_planeOffset);
	pPlaneDef = pPlane2->GetDefinition();

	pPlaneDef->direction = false;
	pPlaneDef->offset = m_L;
	pPlaneDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));

	pPlane2->Create();

	//эскиз
	ksEntityPtr pSketch4 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch4->GetDefinition();
	pSketchDef->SetPlane(pPlane2);
	pSketch4->Create();
	p2DDoc = pSketchDef->BeginEdit();

	double point4[6][6];
	double k = m_dt1 - m_Ddown;
	point4[0][0] = (m_b/2);//right up
	point4[0][1] = ((m_Ddown + k)/2);

	point4[1][0] = -(m_b / 2);//left up
	point4[1][1] = ((m_Ddown + k) / 2);

	point4[2][0] = -(m_b/2);//left down
	point4[2][1] = sqrt(pow(-(m_Ddown / 2), 2) - pow(-(m_Ddown / 2), 2));

	point4[3][0] = m_b / 2;//right up
	point4[3][1] =  sqrt(pow((m_Ddown / 2), 2) - pow((m_Ddown / 2), 2));



	p2DDoc->ksLineSeg(point4[0][0], point4[0][1], point4[1][0], point4[1][1], 1);
	p2DDoc->ksLineSeg(point4[1][0], point4[1][1], point4[2][0], point4[2][1], 1);
	p2DDoc->ksLineSeg(point4[2][0], point4[2][1], point4[3][0], point4[3][1], 1);
	p2DDoc->ksLineSeg(point4[3][0], point4[3][1], point4[0][0], point4[0][1], 1);

	pSketchDef->EndEdit();

	//вырез
	ksEntityPtr pExtrude4 = pPart->NewEntity(o3d_cutExtrusion);

	pExDef = pExtrude4->GetDefinition();
	pExDef->directionType = dtReverse;

	pExDef->SetSketch(pSketch4);
	pExDef->SetSideParam(false, etBlind, m_L1 - m_L2, 0, false);

	pExtrude4->Create();

	//фаски
	ksEntityPtr pChamfer = pPart->NewEntity(o3d_chamfer);

	ksChamferDefinitionPtr pChamferDef = pChamfer->GetDefinition();
	pChamferDef->SetChamferParam(true, 1.6, 1.6);

	fl = pChamferDef->array();
	fl->Clear();
	ksEntityCollectionPtr fledges = pPart->EntityCollection(o3d_edge);
	for (int i = 0; i < fledges->GetCount(); i++)
	{
		ksEntityPtr ed = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();
		if (def->GetOwnerEntity() == pRotate)
		{
			if (def->IsCircle())
			{
				ed->Putname("HoleEdge");
				fl->Add(ed);

			}
		}

	}

	pChamfer->Create();
	


	//иное
	

	 flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();

		if (def->GetOwnerEntity() == pRotate)
		{
			if (def->IsCylinder())
			{
				double h, r;
				def->GetCylinderParam(&h, &r);

				if (r == m_D1 / 2)
				{
					face->Putname("Cylinder1");
					face->Update();
				}
			}	
		}
	}


	


	

	pDoc->SaveAs("D:\KompasPrj\Pol.m3d");
#pragma endregion

  #pragma region Звезда
	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, true);

	pPart = pDoc->GetPart(pTop_Part);



	ksEntityPtr pSketch_1 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch_1->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	pSketch_1->Create();

	p2DDoc = pSketchDef->BeginEdit();

	double point_1[8][2];

	point_1[0][1] = 0;
	point_1[1][1] = 0;

	p2DDoc->ksCircle(point_1[0][1], point_1[1][1], m_dzv / 2, 1);

	pSketchDef->EndEdit();

	//выдавливание
	ksEntityPtr pExtrude_1 = pPart->NewEntity(o3d_bossExtrusion);

	ksBossExtrusionDefinitionPtr pExDef_1 = pExtrude_1->GetDefinition();
	pExDef_1->directionType = dtNormal;

	pExDef_1->SetSketch(pSketch_1);

	pExDef_1->SetSideParam(true, etBlind, m_Hzv, 0, false);

	pExtrude_1->Create();

	flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();

		if (def->GetOwnerEntity() == pExtrude_1)
		{
			if (def->IsCylinder())
			{
				double h, r;
				def->GetCylinderParam(&h, &r);

				if (r == m_dzv / 2)
				{
					face->Putname("CylinderZV");
					face->Update();
				}
			}
			if (def->IsPlanar())
			{
				ksEdgeCollectionPtr col = def->EdgeCollection();

				for (int k = 0; k < col->GetCount(); k++)
				{
					ksEdgeDefinitionPtr d = col->GetByIndex(k);

					if (d->IsCircle())
					{
						ksVertexDefinitionPtr p1 = d->GetVertex(true);

						double x1, y1, z1;

						p1->GetPoint(&x1, &y1, &z1);
						if ((x1 == m_dzv / 2) || (y1 == m_dzv / 2) )
						{
							face->Putname("FaceZV");
							face->Update();
							break;
						}
						
					}
				}


			}

		}

	}
	
	
	

	//зубья
	//эскиз

	ksEntityPtr pSketch_2 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch_2->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	pSketch_2->Create();

	p2DDoc = pSketchDef->BeginEdit();


	double point_2[5][5];
	point_2[0][0] = -(m_B ); //left up
	point_2[0][1] = m_Dzv / 2;

	point_2[1][0] = m_B;//right up
	point_2[1][1] = m_Dzv / 2;

	//right down
	point_2[2][0] = m_B;
	point_2[2][1] = sqrt(pow((m_dzv / 2), 2) - pow(m_B , 2));

	//left down
	point_2[3][0] = -(m_B);
	point_2[3][1] = sqrt(pow(-(m_dzv / 2), 2) - pow(-(m_B), 2));

	point_2[4][0] = 0;
	point_2[4][1] = m_dzv / 2;



	p2DDoc->ksLineSeg(point_2[0][0], point_2[0][1], point_2[1][0], point_2[1][1], 1);
	p2DDoc->ksLineSeg(point_2[1][0], point_2[1][1], point_2[2][0], point_2[2][1], 1);
	p2DDoc->ksArcBy3Points(point_2[2][0], point_2[2][1], point_2[4][0], point_2[4][1], point_2[3][0], point_2[3][1], 1);
	p2DDoc->ksLineSeg(point_2[3][0], point_2[3][1], point_2[0][0], point_2[0][1], 1);

	pSketchDef->EndEdit();

	//выдавливание
	ksEntityPtr pExtrude_2 = pPart->NewEntity(o3d_bossExtrusion);

	pExDef_1 = pExtrude_2->GetDefinition();
	pExDef_1->directionType = dtNormal;

	pExDef_1->SetSketch(pSketch_2);

	pExDef_1->SetSideParam(true, etBlind, m_Hzv, 0, false);

	pExtrude_2->Create();

	 flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();

		if (def->GetOwnerEntity() == pExtrude_2)
		{
			if (def->IsPlanar())
			{
				ksEdgeCollectionPtr col = def->EdgeCollection();

				for (int k = 0; k < col->GetCount(); k++)
				{
					ksEdgeDefinitionPtr d = col->GetByIndex(k);

					if (d->IsStraight())
					{
						ksVertexDefinitionPtr p1 = d->GetVertex(true);

						double x1, y1, z1;

						p1->GetPoint(&x1, &y1, &z1);
						if ((x1 == m_Hzv) || (y1 == m_Hzv))
						{
							face->Putname("FaceBok");
							face->Update();
							break;
						}

					}
				}


			}

		}

	}

	//массив
	ksEntityPtr pCircCopy1 = pPart->NewEntity(o3d_circularCopy);

	pCircDef = pCircCopy1->GetDefinition();

	pCircDef->Putcount2(6);//кол во

	pCircDef->SetAxis(pPart->GetDefaultEntity(o3d_axisOY));//ось


	fl = pCircDef->GetOperationArray();
	fl->Clear();

	fl->Add(pExtrude_2);

	pCircCopy1->Create();

	pDoc->SaveAs("D:\KompasPrj\Zvezda.m3d");
#pragma endregion
    
#pragma region Сборка
	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, false);

	pPart = pDoc->GetPart(pTop_Part);

	ksPartPtr pZvezda, pPol1, pPol2, pPlane_1;
	pDoc->SetPartFromFile("D:\KompasPrj\Zvezda.m3d", pPart, true);
	pDoc->SetPartFromFile("D:\KompasPrj\Pol.m3d", pPart, true);
	pDoc->SetPartFromFile("D:\KompasPrj\Pol.m3d", pPart, true);

	pZvezda = pDoc->GetPart(0);
	pPol1 = pDoc->GetPart(1);
	pPol2 = pDoc->GetPart(2);
	pPlane_1 = pDoc->GetPart(3);
	ksEntityCollectionPtr  col = pZvezda->EntityCollection(o3d_face); //звезда
	ksEntityPtr pZvezdaCylinder = col->GetByName("CylinderZV", true, true);
	ksEntityPtr pZvezdaFace = col->GetByName("FaceZV", true, true);
	ksEntityPtr pZvezdaFaceBok = col->GetByName("FaceBok", true, true);

	col = pPol1->EntityCollection(o3d_face);//полумуфта 1
	ksEntityPtr pPol1Cylinder = col->GetByName("Cylinder1", true, true);//ось полумуфты 1
	ksEntityPtr pPol1Face = col->GetByName("Cylinder4Assembly0", true, true);//боковая поверхность зуба

	col = pPol2->EntityCollection(o3d_face);//полумуфта 2
	ksEntityPtr pPol2Cylinder = col->GetByName("Cylinder1", true, true);//ось полумуфты 2
	
	col = pPol1->EntityCollection(o3d_planeOffset);//плоскость 
	ksEntityPtr _plane = col->GetByName("planePol1", true, true);//плоскость полумуфты 1

	col = pPol2->EntityCollection(o3d_planeOffset);//плоскость 
	ksEntityPtr _plane1 = col->GetByName("planePol1", true, true);//плоскость полумуфты 2
	
	pDoc->AddMateConstraint(mc_Concentric, pPol1Cylinder, pPol2Cylinder, -1, 1, 0);//конц двух полумуфт
	pDoc->AddMateConstraint(mc_Concentric, pPol1Cylinder, pZvezdaCylinder, 1, 1, 0);//конц полумуфты и звёздочки

	pDoc->AddMateConstraint(mc_Coincidence, _plane, pZvezdaFace, -1, 1, 0);//совмещение звезды и поплоскости первой полумуфты
	pDoc->AddMateConstraint(mc_Distance, _plane, _plane1, -1, 1, m_Hzv);//расстояние между полумуфтами
	pDoc->AddMateConstraint(mc_Coincidence, pZvezdaFaceBok,pPol1Face , -1, 1, 0);


	pDoc->RebuildDocument();

#pragma endregion

}

