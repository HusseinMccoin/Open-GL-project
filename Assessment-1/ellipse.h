
void drawEllipse(int rx, int ry, int xc, int yc) {
	float a = rx;
	float b = ry;
	float x = 0;
	float y = ry;
	float d2;
	float d1 = b - (a*a*ry) + (a*a*0.25);

	while (2 * b*b*x < 2 * a*a*y)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d1 < 0)
		{
			x = x + 1;
			d1 = d1 + (2 * b*b*x) + (b*b);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d1 = d1 + (2 * b*b*x) - (2 * a*a*y) + (b*b);
		}
	}//end while

	d2 = b * b*((x + 0.5)*(x + 0.5)) + (a*a*((y - 1)*(y - 1))) - (a*a*b*b);
	while (y > 0 || y < 0)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d2 > 0)
		{
			y = y - 1;
			d2 = d2 - (2 * a*a*y) + (a*a);
		}
		else
		{
			x = x + 1; y = y - 1;
			d2 = d2 + (2 * b*b*x) - (2 * a*a*y) + (a*a);
		}
	}
}