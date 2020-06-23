#include <iostream>
#include <cmath>
#include <vector>
#include "MyForm.h"
#include "Convector.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	À‡·33::MyForm from;
	Application::Run(% from);
}

System::Void À‡·33::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int num1, num2;
	std::string date;
	bool f = true;
	std::vector<int> vhod;
	textBox1->Text = "";
	Convector_String_to_string(textBox4->Text->ToString(), date);
	num1 = Convert::ToInt32(textBox2->Text);
	num2 = Convert::ToInt32(textBox3->Text);
	if (num1 > 32){
		f = false;
	}
	if (num2 < 2){
		f = false;
	}
	if (num2 > 32){
		f = false;
	}
	while (date.size() > 0){
		if ((int)date[date.size() - 1] >= 48 && (int)date[date.size() - 1] <= 57){
			vhod.insert(vhod.begin(), (int)date[date.size() - 1] - 48);
		}
		else if ((int)date[date.size() - 1] >= 65 && (int)date[date.size() - 1] <= 90){
			vhod.insert(vhod.begin(), (int)date[date.size() - 1] - 65 + 10);
		}
		date.erase(date.size() - 1, 1);
	}
	for (int i = 0; i < vhod.size(); i++){
		if (vhod[i] > num1){
			f = false;
		}
	}
	if (f == false){
		MessageBox::Show("Error!", "Calculator");
	}
	int sum = 0;
	for (int i = 0; i < vhod.size(); i++){
		sum += vhod[vhod.size() - 1 - i] * pow(num1, i);
	}
	int summ = sum;
	std::vector<int> v;
	while (summ > 0){
		v.insert(v.begin(), summ % num2);
		summ = summ / num2;
	}
	int j = 0;
	if (f == true){
		char r[10] = "";
		for (int i = 0; i < v.size(); i++){
			if (v[i] < 10){
				textBox1->Text += v[i].ToString();
			}
			else{
				r[0] = 97 + v[i] - 10 - 32;
				textBox1->Text += gcnew System::String(r);
				j++;
			}
		}
	}
	return System::Void();
}

System::Void À‡·33::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label4_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::groupBox2_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::domainUpDown2_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void À‡·33::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}