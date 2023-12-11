#include "Engine.h"

void Engine::input()
{
    Event event;
    const int particleCount = 5;
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
                    int numPoints = rand() % 50 + 25;
                    Vector2i mousePos = Vector2i(event.mouseButton.x, event.mouseButton.y);
                    cout << "Creating Particle At: " << endl;
                    cout << mousePos.x << " " << mousePos.y << endl;
                    Particle P(m_Window, particleCount, mousePos);
                    m_particles.push_back(P);
                }

            }
        }

    }
}

void Engine::update(float dtAsSeconds)
{
    vector<Particle>::iterator it;
    //Fix / Do not increment iterator
    int i = 0;
    //for (auto it = m_particles.begin(); it != m_particles.end(); ++it, i++)
    for (vector<Particle>::iterator it = m_particles.begin(); it != m_particles.end();)
    {
        if (it->getTTL() > 0)
        {
            it->update(dtAsSeconds);
            it++;
            
        }
        else
        {
            it = m_particles.erase(it);
        }
    }
}

void Engine::draw()
{
    m_Window.clear();
    for (int i = 0; i < m_particles.size(); i++)
    {
        //Note:  This will use polymorphism to call your Particle::draw() function
        m_Window.draw(m_particles.at(i));
    }
    m_Window.display();
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

    while (m_Window.isOpen())
    {
        EngineClock.restart();
        Time time = EngineClock.getElapsedTime();
        float seconds = time.asSeconds();
        cout << m_particles.size() << " ";
        input();
        update(time.asSeconds()); // dtseconds
        draw();
        

    }
}
