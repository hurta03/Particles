#include "Engine.h"

void Engine::input()
{
}

void Engine::update(float dtAsSeconds)
{
}

void Engine::draw()
{
}

Engine::Engine()
{
    int xRes = VideoMode::getDesktopMode().width;
    int yRes = VideoMode::getDesktopMode().height;
    VideoMode vm(xRes, yRes);
    m_Window.create(vm, "Particles", Style::Default);

}

void Engine::run()
{
    Clock EngineClock;
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    Event event;
    int particleCount = 5;
    while (m_Window.isOpen())
    {
        EngineClock.restart();
        Time time = EngineClock.getElapsedTime();
        float seconds = time.asSeconds();
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }

        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i < particleCount; i++)
                    {
                        cout << "Creating Particle At: " << endl;
                        int numPoints = rand() % 50 + 25;
                        Vector2i mousePos = Vector2i(event.mouseButton.x, event.mouseButton.y);
                        cout << mousePos.x << " " << mousePos.y << endl;
                    }

                }
            }

        }

        //Update
        m_Window.display();
        m_Window.clear();
    }
}
