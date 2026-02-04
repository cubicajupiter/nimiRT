#include "matrix_invert.h"
#include "miniRT.h"

int	test_matrix(void)
{
	printf("\n####################################### MATRIX TESTS #######################################\n");
	printf("[ DETERMINANTS ]\n");
	t_matrix2 m2;
	t_fl det;

	m2[0][0] = 1.0;
	m2[0][1] = 5.0;
	m2[1][0] = -3.0;
	m2[1][1] = 2.0;
	determinant2(&det, m2);
	printf("determinant: %f\n", det);

	printf("\n[ SUBMATRICES ]\n");
	t_matrix3 m3;
	t_matrix m4;

	m3[0][0] = 1.0;
	m3[0][1] = 5.0;
	m3[0][2] = 0.0;
	m3[1][0] = -3.0;
	m3[1][1] = 2.0;
	m3[1][2] = 7.0;
	m3[2][0] = 0.0;
	m3[2][1] = 6.0;
	m3[2][2] = -3.0;

	m4[0][0] = -6.0;
	m4[0][1] = 1.0;
	m4[0][2] = 1.0;
	m4[0][3] = 6.0;
	m4[1][0] = -8.0;
	m4[1][1] = 5.0;
	m4[1][2] = 8.0;
	m4[1][3] = 6.0;
	m4[2][0] = -1.0;
	m4[2][1] = 0.0;
	m4[2][2] = 8.0;
	m4[2][3] = 2.0;
	m4[3][0] = -7.0;
	m4[3][1] = 1.0;
	m4[3][2] = -1.0;
	m4[3][3] = 1.0;

	int i = 0;
	int j;
	printf("Given a 3x3 Matrix:\n\t%f %f %f\n\t%f %f %f\n\t%f %f %f\n",
		m3[0][0], m3[0][1], m3[0][2], m3[1][0], m3[1][1], m3[1][2], m3[2][0],
		m3[2][1], m3[2][2]);
	printf("m2:\n");
	submatrix2(m2, m3, 0, 2);
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			printf("%f ", m2[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\nAnd Given a 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n", m4[0][0], m4[0][1], m4[0][2], m4[0][3], m4[1][0],
		m4[1][1], m4[1][2], m4[1][3], m4[2][0], m4[2][1], m4[2][2], m4[2][3],
		m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
	printf("m3:\n");
	submatrix3(m3, m4, 2, 1);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%f ", m3[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n[ MINORS ]\n");
	t_matrix2 m2b;
	t_matrix3 m3b;
	t_fl det2;

	m3[0][0] = 3.0;
	m3[0][1] = 5.0;
	m3[0][2] = 0.0;
	m3[1][0] = 2.0;
	m3[1][1] = -1.0;
	m3[1][2] = -7.0;
	m3[2][0] = 6.0;
	m3[2][1] = -1.0;
	m3[2][2] = 5.0;

	m3b[0][0] = 3.0;
	m3b[0][1] = 5.0;
	m3b[0][2] = 0.0;
	m3b[1][0] = 2.0;
	m3b[1][1] = -1.0;
	m3b[1][2] = -7.0;
	m3b[2][0] = 6.0;
	m3b[2][1] = -1.0;
	m3b[2][2] = 5.0;

	printf("Given a 3x3 Matrix:\n\t%f %f %f\n\t%f %f %f\n\t%f %f %f\n",
		m3[0][0], m3[0][1], m3[0][2], m3[1][0], m3[1][1], m3[1][2], m3[2][0],
		m3[2][1], m3[2][2]);
	submatrix2(m2b, m3, 1, 0);
	determinant2(&det2, m2b);
	printf("Determinant via helpers: %f\n", det2);
	t_fl from_minor = minor(NULL, m3b, (int[]){1, 0}, 3);
	printf("Determinant via minor: %f (should be same)\n", from_minor);

	printf("\n[ COFACTORS ]\n");
	m3[0][0] = 3.0;
	m3[0][1] = 5.0;
	m3[0][2] = 0.0;
	m3[1][0] = 2.0;
	m3[1][1] = -1.0;
	m3[1][2] = -7.0;
	m3[2][0] = 6.0;
	m3[2][1] = -1.0;
	m3[2][2] = 5.0;

	printf("Given a 3x3 Matrix:\n\t%f %f %f\n\t%f %f %f\n\t%f %f %f\n",
		m3[0][0], m3[0][1], m3[0][2], m3[1][0], m3[1][1], m3[1][2], m3[2][0],
		m3[2][1], m3[2][2]);
	t_fl dete = minor(NULL, m3b, (int[]){0, 0}, 3);
	printf("Determinant from 0,0: %f\n", dete);
	t_fl cof = cofactor(NULL, m3, (int[]){0, 0}, 3);
	printf("Cofactor from 0,0: %f\n", cof);

	dete = minor(NULL, m3b, (int[]){1, 0}, 3);
	printf("Determinant from 1,0: %f\n", dete);
	cof = cofactor(NULL, m3, (int[]){1, 0}, 3);
	printf("Cofactor from 1,0: %f\n", cof);

	printf("\n[ DETERMINANTS OF LARGE MATRICES ]\n");
	t_fl deter = 0.0;
	m3[0][0] = 1.0;
	m3[0][1] = 2.0;
	m3[0][2] = 6.0;
	m3[1][0] = -5.0;
	m3[1][1] = 8.0;
	m3[1][2] = -4.0;
	m3[2][0] = 2.0;
	m3[2][1] = 6.0;
	m3[2][2] = 4.0;
	printf("Given a 3x3 Matrix:\n\t%f %f %f\n\t%f %f %f\n\t%f %f %f\n",
		m3[0][0], m3[0][1], m3[0][2], m3[1][0], m3[1][1], m3[1][2], m3[2][0],
		m3[2][1], m3[2][2]);
	cof = cofactor(NULL, m3, (int[]){0, 0}, 3);
	printf("Cofactor3: %f\n", cof);
	cof = cofactor(NULL, m3, (int[]){0, 1}, 3);
	printf("Cofactor3: %f\n", cof);
	cof = cofactor(NULL, m3, (int[]){0, 2}, 3);
	printf("Cofactor3: %f\n", cof);
	determinant(&deter, m3, NULL, 3);
	printf("Determinant: %f\n", deter);

	t_fl determ = 0.0;
	m4[0][0] = -2.0;
	m4[0][1] = -8.0;
	m4[0][2] = 3.0;
	m4[0][3] = 5.0;
	m4[1][0] = -3.0;
	m4[1][1] = 1.0;
	m4[1][2] = 7.0;
	m4[1][3] = 3.0;
	m4[2][0] = 1.0;
	m4[2][1] = 2.0;
	m4[2][2] = -9.0;
	m4[2][3] = 6.0;
	m4[3][0] = -6.0;
	m4[3][1] = 7.0;
	m4[3][2] = 7.0;
	m4[3][3] = -9.0;
	printf("And Given a 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n", m4[0][0], m4[0][1], m4[0][2], m4[0][3], m4[1][0],
		m4[1][1], m4[1][2], m4[1][3], m4[2][0], m4[2][1], m4[2][2], m4[2][3],
		m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
	cof = cofactor(m4, NULL, (int[]){0, 0}, 4);
	printf("\nCofactor4: %f\n", cof);
	cof = cofactor(m4, NULL, (int[]){0, 1}, 4);
	printf("Cofactor4: %f\n", cof);
	cof = cofactor(m4, NULL, (int[]){0, 2}, 4);
	printf("Cofactor4: %f\n", cof);
	cof = cofactor(m4, NULL, (int[]){0, 3}, 4);
	printf("Cofactor4: %f\n", cof);
	determinant(&determ, NULL, m4, 4);
	printf("Determinant: %f\n", determ);

	printf("\n[ INVERSION ]\n");
	t_fl determi = 0.0;
	m4[0][0] = 6.0;
	m4[0][1] = 4.0;
	m4[0][2] = 4.0;
	m4[0][3] = 4.0;
	m4[1][0] = 5.0;
	m4[1][1] = 5.0;
	m4[1][2] = 7.0;
	m4[1][3] = 6.0;
	m4[2][0] = 4.0;
	m4[2][1] = -9.0;
	m4[2][2] = 3.0;
	m4[2][3] = -7.0;
	m4[3][0] = 9.0;
	m4[3][1] = 1.0;
	m4[3][2] = 7.0;
	m4[3][3] = -6.0;
	printf("Given a 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n", m4[0][0], m4[0][1], m4[0][2], m4[0][3], m4[1][0],
		m4[1][1], m4[1][2], m4[1][3], m4[2][0], m4[2][1], m4[2][2], m4[2][3],
		m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
	determinant(&determi, NULL, m4, 4);
	printf("Determinant: %f\n", determi);
	printf("is invertible (bool): %d\n", is_invertible(m4));

	t_fl determin = 0.0;
	m4[0][0] = -4.0;
	m4[0][1] = 2.0;
	m4[0][2] = -2.0;
	m4[0][3] = -3.0;
	m4[1][0] = 9.0;
	m4[1][1] = 6.0;
	m4[1][2] = 2.0;
	m4[1][3] = 6.0;
	m4[2][0] = 0.0;
	m4[2][1] = -5.0;
	m4[2][2] = 1.0;
	m4[2][3] = -5.0;
	m4[3][0] = 0.0;
	m4[3][1] = 0.0;
	m4[3][2] = 0.0;
	m4[3][3] = 0.0;
	printf("\nAnd Given a 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n", m4[0][0], m4[0][1], m4[0][2], m4[0][3], m4[1][0],
		m4[1][1], m4[1][2], m4[1][3], m4[2][0], m4[2][1], m4[2][2], m4[2][3],
		m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
	determinant(&determin, NULL, m4, 4);
	printf("Determinant: %f\n", determin);
	printf("is invertible (bool): %d\n", is_invertible(m4));

	m4[0][0] = -5.0;
	m4[0][1] = 2.0;
	m4[0][2] = 6.0;
	m4[0][3] = -8.0;
	m4[1][0] = 1.0;
	m4[1][1] = -5.0;
	m4[1][2] = 1.0;
	m4[1][3] = 8.0;
	m4[2][0] = 7.0;
	m4[2][1] = 7.0;
	m4[2][2] = -6.0;
	m4[2][3] = -7.0;
	m4[3][0] = 1.0;
	m4[3][1] = -3.0;
	m4[3][2] = 7.0;
	m4[3][3] = 4.0;
	printf("\nGiven the TO-BE-INVERTED 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n\t%f %f %f %f\n", m4[0][0], m4[0][1], m4[0][2],
		m4[0][3], m4[1][0], m4[1][1], m4[1][2], m4[1][3], m4[2][0], m4[2][1],
		m4[2][2], m4[2][3], m4[3][0], m4[3][1], m4[3][2], m4[3][3]);
	determinant(&determin, NULL, m4, 4);
	printf("Determinant: %f\n", determin);
	cof = cofactor(m4, NULL, (int[]){2, 3}, 4);
	printf("Cofactor a[3][2]: %f\n", cof);

	t_matrix m4b;
	matrix_invert(m4b, m4);
	printf("B[3,2]: %f should be -160/532: %f / %f\n", m4b[3][2], m4b[3][2]
		* 532.0, 532.0);
	cof = cofactor(m4, NULL, (int[]){3, 2}, 4);
	printf("Cofactor a[2][3]: %f\n", cof);
	printf("B[2,3]: %f should be -160/532: %f / %f\n", m4b[2][3], m4b[2][3]
		* 532.0, 532.0);
	printf("\nNOW INVERTED 4x4 Matrix:\n\t%f %f %f %f\n\t%f %f %f %f\n\t%f %f %f\
		%f\n\t%f %f %f %f\n", m4b[0][0], m4b[0][1], m4b[0][2], m4b[0][3],
		m4b[1][0], m4b[1][1], m4b[1][2], m4b[1][3], m4b[2][0], m4b[2][1],
		m4b[2][2], m4b[2][3], m4b[3][0], m4b[3][1], m4b[3][2], m4b[3][3]);

	printf("\n[ INVERSION - MAXIMAL TESTING ]\n");
	t_matrix d;
	m4[0][0] = 8.0;
	m4[0][1] = -5.0;
	m4[0][2] = 9.0;
	m4[0][3] = 2.0;
	m4[1][0] = 7.0;
	m4[1][1] = 5.0;
	m4[1][2] = 6.0;
	m4[1][3] = 1.0;
	m4[2][0] = -6.0;
	m4[2][1] = 0.0;
	m4[2][2] = 9.0;
	m4[2][3] = 6.0;
	m4[3][0] = -3.0;
	m4[3][1] = 0.0;
	m4[3][2] = -9.0;
	m4[3][3] = -4.0;
	matrix_invert(d, m4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%f", d[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");

	t_matrix destinat;
	m4[0][0] = 9.0;
	m4[0][1] = 3.0;
	m4[0][2] = 0.0;
	m4[0][3] = 9.0;
	m4[1][0] = -5.0;
	m4[1][1] = -2.0;
	m4[1][2] = -6.0;
	m4[1][3] = -3.0;
	m4[2][0] = -4.0;
	m4[2][1] = 9.0;
	m4[2][2] = 6.0;
	m4[2][3] = 4.0;
	m4[3][0] = -7.0;
	m4[3][1] = 6.0;
	m4[3][2] = 6.0;
	m4[3][3] = 2.0;
	matrix_invert(destinat, m4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%f", destinat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	t_matrix A;
	A[0][0] = 3.0;
	A[0][1] = -15.0;
	A[0][2] = 7.0;
	A[0][3] = 3.0;
	A[1][0] = 3.0;
	A[1][1] = 3.0;
	A[1][2] = 2.0;
	A[1][3] = -9.0;
	A[2][0] = -4.0;
	A[2][1] = 4.0;
	A[2][2] = 4.0;
	A[2][3] = 66.0;
	A[3][0] = -6.0;
	A[3][1] = 5.0;
	A[3][2] = -1.0;
	A[3][3] = 11.0;

	t_matrix b;
	b[0][0] = 8.0;
	b[0][1] = 2.0;
	b[0][2] = 2.0;
	b[0][3] = 2.0;
	b[1][0] = 3.0;
	b[1][1] = -1.0;
	b[1][2] = 7.0;
	b[1][3] = 0.0;
	b[2][0] = 7.0;
	b[2][1] = 0.0;
	b[2][2] = 5.0;
	b[2][3] = 4.0;
	b[3][0] = 6.0;
	b[3][1] = -2.0;
	b[3][2] = 0.0;
	b[3][3] = 5.0;

	printf("\n\n\n");
	t_matrix C;
	matrix_multiply(C, A, b);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%.15f", C[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	t_matrix B_invert;
	matrix_invert(B_invert, b);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%.15f", B_invert[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	t_matrix A_1;
	matrix_multiply(A_1, C, B_invert);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%.15f", A_1[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("\t%.15f", A[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	if (matrix_compare(A_1, A) == TRUE)
		printf("same\n");
	else
		printf("fail\n");

	printf("\n####################################### END OF MATRIX TESTS #######################################\n");
	return (0);
}
