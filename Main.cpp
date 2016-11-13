# include <Siv3D.hpp>

Image CreateDiceImage(int32 resolution = 128)
{
	Image image(resolution * 3, resolution * 2, Palette::White);

	const double r = resolution / 100.0;

	// [1]
	Circle(r * 50, r * 50, r * 18).write(image, Palette::Red);

	// [2]
	Circle(r * 122, r * 22, r * 11).write(image, Palette::Black);
	Circle(r * 178, r * 78, r * 11).write(image, Palette::Black);

	// [3]
	Circle(r * 278, r * 22, r * 11).write(image, Palette::Black);
	Circle(r * 250, r * 50, r * 11).write(image, Palette::Black);
	Circle(r * 222, r * 78, r * 11).write(image, Palette::Black);

	// [4]
	Circle(r * 122, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 122, r * 178, r * 11).write(image, Palette::Black);
	Circle(r * 178, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 178, r * 178, r * 11).write(image, Palette::Black);

	// [5]
	Circle(r * 22, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 22, r * 178, r * 11).write(image, Palette::Black);
	Circle(r * 50, r * 150, r * 11).write(image, Palette::Black);
	Circle(r * 78, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 78, r * 178, r * 11).write(image, Palette::Black);

	// [6]
	Circle(r * 227, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 227, r * 150, r * 11).write(image, Palette::Black);
	Circle(r * 227, r * 178, r * 11).write(image, Palette::Black);
	Circle(r * 273, r * 122, r * 11).write(image, Palette::Black);
	Circle(r * 273, r * 150, r * 11).write(image, Palette::Black);
	Circle(r * 273, r * 178, r * 11).write(image, Palette::Black);

	return image.fit(resolution, resolution);
}

Image CreateMatImage(int32 resolution = 512)
{
	return Image(resolution, resolution, [](auto)
	{
		return HSV(150, 0.9, Random(0.65, 0.7));
	});
}

void Main()
{
	Graphics3D::SetAmbientLight(ColorF(0.3));

	const Texture textureMat(CreateMatImage(512), TextureDesc::For3D);

	const Texture textureDice(CreateDiceImage(256), TextureDesc::For3D);

	const Mesh meshDice(MeshData::Box6(1.0));

	while (System::Update())
	{
		Graphics3D::FreeCamera();

		Plane(16).draw(textureMat);

		meshDice.translated(0, 0.5, 0).draw(textureDice).drawShadow();

		meshDice.rotated(180_deg, 20_deg, 0).translated(2, 0.5, -0.5).draw(textureDice).drawShadow();

		meshDice.rotated(90_deg, 280_deg, 90_deg).translated(-1, 0.5, -1.5).draw(textureDice).drawShadow();
	}
}
