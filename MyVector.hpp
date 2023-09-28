#pragma once
#include <iostream>
#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_
namespace std {
	class VEC_EXCEPTION : public std::exception //定义错误类，为以后的抛出错误做准备
	{
	public:
		const char* what() const noexcept{
			return "Out Of Index";
		}
	};

	template<class _Ty>
	class vector
	{
	public:
		vector()noexcept{
			this->_Size = 0;
			this->_Capacity = 50;
			this->_vec = new _Ty[this->_Capacity];
		}
		vector(int capacity)noexcept{
			this->_Size = 0;
			this->_Capacity = capacity;
			this->_vec = new _Ty[this->_Capacity];
		}
		vector(const vector& S2)noexcept{
			this->_Capacity = S2._Capacity;
			this->_Size = 0;
			this->_vec = new _Ty[S2._Capacity];
			for (int i = 0; i < S2._Size; i++){
				this->_vec[i] = S2._vec[i];
				this->_Size++;
			}
		}
		void push_back(_Ty val)noexcept{
			_Check_Extend_Size();
			this->_vec[this->_Size] = val;
			this->_Size++;
		}
		void pop_back()noexcept{
			this->_Size--;
		}
		_Ty back()noexcept{
			return this->_vec[this->_Size - 1];
		}
		_Ty front(){
			if (this->_Size = 0){
				throw VEC_EXCEPTION();
			}
			return this->_vec[0];
		}
		int Size() noexcept{
			return this->_Size;
		}
		int Capacity() noexcept{
			return this->_Capacity;
		}
		void reserve(int Size) noexcept{
			this->_reserveSize = new _Ty[Size];
			this->_reserve = Size;
		}
		int find(_Ty val) noexcept{
			for (int i = 0; i < this->_Size; i++){
				if (this->_vec[i] == val){
					return i;
				}
			}
		}
		int rfind(_Ty val) noexcept {
			for (int i = this->_Size; i > 0; i--){
				if (this->_vec[i] == val){
					return i;
				}
			}
		}
		void push_front(_Ty val) noexcept{
			this->insert(0, val);
		}
		void insert(int index, _Ty val) noexcept{
			_Check_Extend_Size();
			_Ty last = this->_vec[this->_Size - 1];
			for (int i = this->_Size; i > index; i--){
				_Ty temp = this->_vec[i];
				this->_vec[i] = this->_vec[i - 1];
				this->_vec[i - 1] = temp;
			}
			this->_vec[index] = val;
			this->_vec[this->_Size] = last;
			this->_Size++;
		}
		_Ty& operator[](int index){
			if (index >= this->_Size){
				throw VEC_EXCEPTION();
			}
			return this->_vec[index];
		}
		vector<_Ty>& operator=(const vector<_Ty>& S2) noexcept{
			this->_Capacity = S2._Capacity;
			this->_Size = S2._Size;
			this->_vec = new _Ty[S2._Size];
			for (int i = 0; i < this->_Size; i++){
				this->_vec[i] = S2._vec[i];
			}
		}
		~vector(){
			if (this->_vec != NULL) {
				delete[] this->_vec;
				this->_vec = NULL;
			}
		}
	private:
		void _Check_Extend_Size(){
			if (this->_Size >= this->_Capacity){
				if ((this->_reserveSize != NULL) && (this->_reserve >= this->_Capacity)){
					for (int i = 0; i < this->_Size; i++){
						this->_reserveSize[i] = this->_vec[i];
					}
					this->_vec = this->_reserveSize;
				}else{
					_Ty* newSize = new _Ty[this->_Capacity * 2];
					for (int i = 0; i < this->_Size; i++){
						newSize[i] = this->_vec[i];
					}
					this->_vec = newSize;
				}
				this->_reserve = 0;
				this->_reserveSize = NULL;
			}
		}

		int _Size;
		int _Capacity;
		int _reserve;
		_Ty* _vec;
		_Ty* _reserveSize;
	};
};
#endif // _MY_VECTOR_HPP_
