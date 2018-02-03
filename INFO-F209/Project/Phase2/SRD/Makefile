 
all: SRD.pdf

SRD.pdf: SRD.tex
	pdflatex $^
	pdflatex $^
	
clean:
	rm -f *.aux *.log *.toc
	rm -f *.idx *.glo *.ilg *.ind *.ist
	
mrproper: clean 
	rm -f SRD.pdf

.PHONY: all clean mproper
