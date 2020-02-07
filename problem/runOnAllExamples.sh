#!/bin/bash

main() {
	echo "Berechne alle Aufgaben..."
	echo
	echo "1/15..."
	./solution input/easy_1.graph
	echo "2/15..."
	./solution input/easy_2.graph
	echo "3/15..."
	./solution input/easy_3.graph
	echo "4/15..."
	./solution input/easy_4.graph
	echo "5/15..."
	./solution input/easy_5.graph
	echo "6/15..."
	./solution input/medium_1.graph
	echo "7/15..."
	./solution input/medium_2.graph
	echo "8/15..."
	./solution input/medium_3.graph
	echo "9/15..."
	./solution input/medium_4.graph
	echo "10/15..."
	./solution input/medium_5.graph
	echo "11/15..."
	./solution input/hard_1.graph
	echo "12/15..."
	./solution input/hard_2.graph
	echo "13/15..."
	./solution input/hard_3.graph
	echo "14/15..."
	./solution input/hard_4.graph
	echo "15/15..."
	./solution input/hard_5.graph
	echo -e "\033[33mDie Berechnung ist abgeschlossen!\033[0m"
}

main