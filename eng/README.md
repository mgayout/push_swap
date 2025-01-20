# <p align="center">PUSH_SWAP [42 Project]</p>

<div align="center">
	<table>
		<tr><th>GRADE</th>
		<th>FRENCH VERSION</th></tr>
		<tr><th><img src="https://github.com/mgayout/mgayout/blob/main/img/note/96.png" height="100"></th>
		<th><a href= "https://github.com/mgayout/push_swap"><img src="https://github.com/mgayout/mgayout/blob/main/img/french.png" height="100"></a></th></tr>
	</table>
</div>

The `PUSH_SWAP` project is a program that sorts a series of numbers.

In this project, I used an `insertion sort` algorithm based on the work of <a href="https://medium.com/@ayogun/push-swap-c1f5d2d41e97">A. Yigit Ogun</a>.

In summary, here is the logic of this algorithm:

* The first 3 numbers are inserted into a linked list `(B)` and the rest into a second list `(A)`.

* A `target` is assigned to each value in list A.
	* This target is a value from list B, lower and closest to our value from list A. 

* A `cost` is assigned to each value in list A.
	* This cost represents the number of moves so that the value of A and the target of the value of A end up at the top of the list.

*The lowest cost represents the value moved from list A to list B.

* To have a set of sorted values, simply return the values ​​from list B to list A in ascending order.

In addition to the request for the use of an efficient algorithm, the `PUSH_SWAP` project allows us to understand the principle of `HEAP` and `STACK`.

<p align="center"><img src="clip/ps.gif" height="100"></p>

## <p> </p>

## <p align="center">INSTALLATION</p>

* To download `PUSH_SWAP` :

```shell
git clone https://github.com/mgayout/push_swap.git
```
<div align="center">
	<table>
		<tr><th colspan="2" align="center">Règles</th></tr>
		<tr><td align="center">make</td>
		<td>Compilation</td></tr>
		<tr><td align="center">make clean</td>
		<td>Deleting object files</td></tr>
		<tr><td align="center">make fclean</td>
		<td>Deleting object files and the programm push_swap</td></tr>
		<tr><td align="center">make re</td>
		<td>Deleting object files and the programm followed by compilation</td></tr>
	</table>
</div>

* To test `PUSH_SWAP` :

```shell
./push_swap "1 2 3"
```
or
```shell
./push_swap 1 2 3
```
or
```shell
./push_swap $(seq $a $b | shuf -n $c | tr '\n' ' ')
```
* `seq` allows you to define a set of values ​​with `$a` as the minimum value and `$b` as the maximum value.

* `shuf` allows you to randomly generate numbers with `$c` representing the number of values ​​generated.

* `tr` allows you to replace one character with another.
	* Here in the example, replace '\n' with a ' '.