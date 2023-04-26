#pragma once
#include <msclr/marshal_cppstd.h> 
#include"Cdeciamal.h"

namespace decimalforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для F_decimal
	/// </summary>
	public ref class F_decimal : public System::Windows::Forms::Form
	{
	public:
		F_decimal(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~F_decimal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input a:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Input b:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(107, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(135, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(107, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(135, 26);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(107, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"addition";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &F_decimal::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(107, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(117, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"substraction";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &F_decimal::button2_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(174, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Result in standart form:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(50, 245);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(151, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Result in short form:";
			// 
			// F_decimal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 284);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"F_decimal";
			this->Text = L"F_decimal";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		   
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "")
			MessageBox::Show(this, "Заполнены не все переменные", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			String^ var_a = textBox1->Text;
			std::string s_a = msclr::interop::marshal_as<std::string>(var_a);
			String^ var_b = textBox2->Text;
			std::string s_b = msclr::interop::marshal_as<std::string>(var_b);
			decimal a(s_a);
			decimal b(s_b);
			decimal res = a + b;
			s_decimal s_res;
			s_res = res;
			System::String^ sys_res = msclr::interop::marshal_as<System::String^>(res.get_num());
			label3->Text = "Result in standart form:" + sys_res;
			System::String^ sys_s_res = msclr::interop::marshal_as<System::String^>(s_res.get_num());
			label4->Text = "Result in short form:" + sys_s_res;
		}
	}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" || textBox2->Text == "")
		MessageBox::Show(this, "Заполнены не все переменные", "Сообщение",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		String^ var_a = textBox1->Text;
		std::string s_a = msclr::interop::marshal_as<std::string>(var_a);
		String^ var_b = textBox2->Text;
		std::string s_b = msclr::interop::marshal_as<std::string>(var_b);
		decimal a(s_a);
		decimal b(s_b);
		decimal res = a - b;
		s_decimal s_res;
		s_res = res;
		System::String^ sys_res = msclr::interop::marshal_as<System::String^>(res.get_num());
		label3->Text = "Result in standart form: " + sys_res;
		System::String^ sys_s_res = msclr::interop::marshal_as<System::String^>(s_res.get_num());
		label4->Text = "Result in short form:" + sys_s_res;
	}

}
};
}
